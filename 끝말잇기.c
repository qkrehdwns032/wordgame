#include <stdio.h>
#include <string.h>
#include <windows.h>

int cheak = 0;
int player1Y = 6;

void gotoxy(int x, int y)
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void setColor(unsigned short text, unsigned short back)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (back << 4));
}

int main(void)
{
	char first[46];
	char end[46];
	int player = 1;
	int count = 1;
	char save[100][47];
	int saveCount = 0;
	int cheakNumber = 0;
	int x = 0, y = 0;
	
	int player2Y = 5;

	gotoxy(41, 2);
	setColor(10, 0);
	printf("�� �� �� �� �� ��\n");
	setColor(6,0);
	gotoxy(45, 4);
	printf("���� ����!\n");
	gotoxy(17, player1Y);
	printf("%dȸ player1:",count);

	while (1)
	{	
		setColor(11, 0);
		gets(first);// ����Ű �Է�����
		setColor(6, 0);

		if (strlen(first) < 2)
		{
			setColor(4, 0);
			gotoxy(38, player1Y + 2);
			printf("2���� �̻� ���ܾ �Է��ؾ��մϴ�~\n");
			Sleep(1500);
			printf("\033[1A");  // Ŀ���� �� �� ���� �̵�
			printf("\033[2K");  // ���� ���� �����
			gotoxy(29, player1Y);
			setColor(6, 0);
		}
		else
		{
			break;
		}
	}

	for (int i = 0; i < strlen(first)+1; i++)
	{
		save[saveCount][i] = first[i];
	}

	count++;
	saveCount++;

	while (1)
	{
		if (player == 1)
		{
			player2Y++;
			gotoxy(65,player2Y);
			printf("%dȸ player2:",count);
		}
		else
		{
			player1Y++;
			gotoxy(17, player1Y);
			printf("%dȸ player1:",count);
		}
		while (1)
		{
			setColor(11, 0);
			gets(end);  // ����Ű �Է�����  
			setColor(6, 0);

			if (strlen(end) < 2)
			{
				setColor(4, 0);
				gotoxy(38, player1Y + 2);
				printf("2���� �̻��� ���ܾ �Է��ؾ��մϴ�~\n");
				Sleep(1500);
				printf("\033[1A");  // Ŀ���� �� �� ���� �̵�
				printf("\033[2K");  // ���� ���� �����
				if (player == 0)
				{
					gotoxy(29, player1Y);
				}
				else
				{
					gotoxy(77, player1Y);
				}
				setColor(6, 0);
			}
			else
			{
				break;
			}
		}
		
		if (first[strlen(first)-1]!=end[0])
		{
			setColor(4, 0);
			gotoxy(38, player1Y + 2);
			printf("Ʋ�Ƚ��ϴ�!");
			setColor(6, 0);
			break;
		}

		for (int i = 0; i < saveCount; i++)
		{
			int len1 = strlen(save[i]);
			int len2 = strlen(end);
			if(len1==len2)
			{
				for (int j = 0; j < len2; j++)
				{
					if (save[i][j] != end[j])
					{
						cheakNumber = 1;
					}
				}
				if (cheakNumber == 0)
				{
					setColor(4, 0);
					gotoxy(38, player1Y + 2);
					printf("�ߺ��� ���ܾ��Դϴ�!\n");
					gotoxy(43, player1Y + 3);
					printf("�����ϴ�!");
					setColor(15, 0);
					return 1;
				}
			}
			cheakNumber = 0;
		}
		

		for (int i = 0; i < strlen(end) + 1; i++)
		{
			save[saveCount][i] = end[i];
		}

		strcpy(first, end);

		if (player == 1)
		{
			player = 0;
		}
		else
		{
			player = 1;
		}
		count++;
		saveCount++;
	}

	setColor(15, 0);
	return 0;
}