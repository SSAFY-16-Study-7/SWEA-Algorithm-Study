# 🚀 알고리즘 코딩 테스트 스터디 (Study Workflow)

저희 코딩 테스트 스터디의 진행 방식 및 팀원용 주간 워크플로우 가이드입니다.  
모든 스터디원은 매주 아래 절차에 따라 문제 풀이 제출 및 코드 리뷰를 진행해 주세요.

---

## 📅 주간 일정 한눈에 보기

| 요일             | 진행 내용                                                 | 비고                  |
|:-----------------|:----------------------------------------------------------|:----------------------|
| **화요일**       | 주차별 출제자가 문제 3개 선정 및 공지                     | Slack / 카카오톡 공지 |
| **화 ~ 월**      | 문제 풀이, 로컬 커밋 및 **PR(Pull Request) 생성**         | 미팅 전 제출 필수     |
| **화요일 18:00** | **[마감]** 모든 팀원 PR 제출 & 서로의 코드 리뷰 작성 마감 |                       |
| **화요일 18:00** | **온라인 스터디 미팅 (약 60분)**                          | Discord / Google Meet |

---

## 📂 1. 저장소 폴더 구조 규칙

모든 풀이 코드는 `week00/본인아이디/` 폴더 하위에 저장합니다.

```text
algorithm-study/
├── .github/
│   └── PULL_REQUEST_TEMPLATE.md
├── README.md
├── week01/
│   ├── yourId/
│   │   ├── SWEA_2001.cpp
│   │   ├── SWEA_1979.cpp
│   │   └── SWEA_2817.cpp
│   ├── kim/
│   └── lee/
└── week02/
    └── ...
```

---

## 🔄 2. 팀원별 주간 워크플로우 (Step-by-Step)

### Step 1. 최신 `main` 브랜치 동기화 및 작업 브랜치 생성

주차마다 본인의 작업 브랜치를 새로 생성합니다.  
브랜치 이름 규칙: `feature/week주차-본인아이디`

```bash
# 1. main 브랜치 이동 및 최신화
git checkout main
git pull origin main

# 2. 이번 주차 작업 브랜치 생성 및 이동
git checkout -b feature/week01-yourId
```

---

### Step 2. 문제 풀이 및 코드 작성

1. 해당 주차 폴더 및 개인 아이디 폴더를 생성합니다. (예: `week01/yourId/`)
2. 풀이 파일명 규칙: `플랫폼_문제번호.cpp` (예: `SWEA_2001.cpp`, `BOJ_1000.cpp`)
3. 코드를 커밋하고 GitHub에 푸시합니다.

```bash
# 변경사항 스테이징 & 커밋
git add .
git commit -m "feat: week01 SWEA 2001 파리퇴치 풀이 완료"

# 본인 브랜치로 푸시
git push origin feature/week01-hong
```

---

### Step 3. Pull Request (PR) 생성

1. GitHub 저장소로 이동하여 **`Compare & pull request`** 버튼을 클릭합니다.
2. **Title (제목) 규칙:** `[week01] 홍길동 문제 풀이 제출`
3. PR 생성 시 **자동으로 표시되는 템플릿**을 양식에 맞게 작성합니다.
4. 우측 **`Projects`** 항목에서 스터디 프로젝트를 연결하고, `Assignees`에 본인을 지정합니다.
5. **`Create pull request`**를 눌러 PR을 등록합니다.

---

### Step 4. 코드 리뷰 (Peer Review) 참여하기

> 💡 다른 사람의 코드를 읽고 질문과 피드백을 남기는 단계입니다.

1. 팀원의 PR 페이지로 이동하여 **`Files changed`** 탭을 클릭합니다.
2. 피드백을 남기고 싶은 코드 줄 번호 옆의 **`+`** 버튼을 누릅니다.
3. 질문, 개선 아이디어, 칭찬 등을 자유롭게 작성합니다.
    * *예시: "이 부분 $O (N^2)$ 대신 투 포인터를 쓰면 $O (N)$으로 줄일 수 있을 것 같아요!"*
    * *예시: "비트마스킹 조건식 처리가 깔끔하네요. 많이 배웠습니다."*
4. 리뷰를 완료하면 **`Review changes`** $
   ightarrow$ **`Comment`** 또는 **`Approve`**를 제출합니다.

---

### Step 5. 스터디 미팅 후 Merge

1. 화요일 미팅에서 피드백 및 디버깅 토론을 진행합니다.
2. 미팅 종료 후, 본인의 PR 페이지에서 **`Merge pull request`** 버튼을 눌러 `main` 브랜치에 병합합니다.
3. 로컬의 작업 브랜치를 정리합니다.

```bash
git checkout main
git pull origin main
git branch -d feature/week01-yourId
```