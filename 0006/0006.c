#include <stdio.h>
#include <string.h>
#define N 10
#define M 6

void main()
{
	char medicine[M][12] = {"파스", "밴드", "타이레놀", "이지엔6", "훼스탈", "래피콜"};
	char information[M][100] = {"파스", "밴드", "감기 관련, 발열 / 4-6시간마다 2정(1일 최대 8)",
								"두통, 해열, 생리통 / 1회 1-2캡슐, 1일 1-3회(4시간 이상)", "소화불량, 식욕감퇴 / 1회 1-2정, 1일 3회(2시간 이상)", "종합감기약 / 1회 2캡슐, 1일 3회(식후 30분)"};
	char discard[M][50] = {"일반쓰레기", "일반쓰레기", "포장지 분리 후 배출", "포장지, 캡슐껍질 분리 후 배출",
						   "포장지 분리 후 배출", "포장지, 캡슐껍질 분리 후 배출"};

	int stu_num[N];
	char student[N][12];
	char medi_get[N][12];
	int medi_num[N];
	int i, j, num, cnt1 = 0, cnt2 = 0;

	for (i = 1;; i++)
	{
		printf("\n학번을 입력해주세요. ");
		scanf("%d", &num);

		if (num != 0000)
		{
			stu_num[i] = num;

			printf("이름을 입력해주세요. ");
			scanf("%s", student[i]);

			printf("약 이름을 입력해주세요. ");
			scanf("%s", medi_get[i]);

			printf("가져가는 약의 수량을 입력해주세요. ");
			scanf("%d", &medi_num[i]);
			cnt1++;

			printf("-------------------------------------------\n");
			for (j = 0; j < M; j++)
			{
				if (strcmp(medicine[j], medi_get[i]) == 0)
				{
					cnt2++;
					printf("<%s 정보>\n- %s\n폐기방법 : %s", medi_get[i], information[j], discard[j]);
				}
			}
			if (cnt2 == 0)
			{
				printf("일치하는 약의 정보가 없습니다.");
			}
			cnt2 = 0;
			printf("\n===========================================\n");
		}

		else
		{
			printf("\n===========================================\n");
			printf("\n안녕하세요 선생님");
			if (cnt1 != 0)
			{
				printf("\n총 %d명의 학생이 약을 가져갔습니다.", cnt1);
				printf("\n------------------------------------------------");
				printf("\n       학번      이름       약 종류       수량 ");
				printf("\n------------------------------------------------");
				for (j = 1; j <= cnt1; j++)
				{
					printf("\n %d     %d      %s       %s       %d ", j, stu_num[j], student[j], medi_get[j], medi_num[j]);
				}
			}
			else
			{
				printf("\n약을 가져간 학생이 없습니다.");
			}
			printf("\n===========================================\n");
			// break;
		}
	}
}
