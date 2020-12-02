#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
	int n, m, sum = 0, k; //급식실 인원을 n, 대기자 수를 m, 오늘 급식 먹은 사람 총 숫자=sum
	int case1;

	// 몇 개의 반이 먹었는지
	int classes = 0;

	printf("맨 처음으로 몇 반이 먹나요?(1~3반)\n");
	scanf("%d", &case1);

	if (case1 == 1)
		printf("1,2,3반 순으로 입장하세요.\n");
	else if (case1 == 2)
		printf("2,3,1반 순으로 입장하세요.\n");
	else if (case1 == 3)
		printf("3,1,2반 순으로 입장하세요.\n");

	n = 20;
	m = 20; //~~반 내려오세요 하고 공지하면 그때마다 m에 숫자를 더해줘야함.(한 반에 20명이니까 m=m+20; 하면 되지 않을까..?)
	// 한 반은 내려온 상태니까
	classes = 1;

	// 이거는 프로그램 맨 앞에 한번만!
	srand(time(NULL)); //난수를 뽑는 seed 리스트를 무작위로 뽑기 위해.

	while (1) // 한 반에 20명 있다고 했을 때 전교 인원이 180명 이므로 180명이 모두 밥을 먹으면 이 프로그램이 종료된다.
	{
		int range;
		range = (5 - 1) + 1; //무작위 숫자 1부터 5사이를 구하고 싶을 때.

		k = rand() % range + 1; //k는 매번 식사를 마친 사람 수이므로 무작위로 바뀐다.

		printf("(%d명 대기중.)\n", m);
		printf("(%d명이 식사를 마쳤습니다.)\n", k);

		//k명 나갔으니까 k명 들어오라고 하는게 원칙인데, 만약에 줄 서 있는 사람이 3명인데 5명이 밥 다 먹었다고 5명 들어오세요~하면 이상하니까 줄 서 있는 사람이 5명 이하일 떄는 남아있는 사람 전부 들어오세요 이런 식으로.
		if (m >= 5)
		{
			printf("%d명 식사하러 들어오세요.\n", k);
			m = m - k;
			sum = sum + k;
		}
		else
		{
			printf("마지막 %d명 식사하러 들어오세요~!~!\n", m);
			m = 0;

			// 줄이 다 없어졌는데 남은 반이 없으면 끝난거지
			if (classes >= 9)
			{
				break;
			}

			// 줄이 다 없어졌으니까 다음 반이 들어와야겠지?
			classes++;
			// 식은 왜 이렇게 나오는지 잘 고민해봐
			printf("%d학년 %d반 식사!\n", (9 - classes) / 3 + 1, 4 - ((((9 - classes) % 3) + 4 - case1) % 3 + 1));
			// 한 반이 다시 대기중
			m = 20;
		}
		printf("(전체방송)아직 식사를 하지 않은 학생들은 식사하러오기 바랍니다.\n\n\n");
	}
}