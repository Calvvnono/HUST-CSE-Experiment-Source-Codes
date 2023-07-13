#include<stdio.h>
#include<malloc.h>

typedef struct stu
{
	char stu_num[20];
	char name[20];
	int eng;
	int mat;
	int phy;
	int c;
	int sum;
	struct stu* next;
}gra, * grap;

grap input_grades()
{
	int n, i;
	scanf("%d", &n);
	static gra head;
	grap left = &head, right = NULL;
	for (i = 0; i < n; i++)
	{
		right = (grap)malloc(sizeof(gra));
		scanf("%s%s%d%d%d%d", &right->stu_num, &right->name, &right->eng, &right->mat, &right->phy, &right->c);
		right->sum = right->eng + right->mat + right->phy + right->c;
		left->next = right;
		right->next = NULL;
		left = right;
	}
	printf("完成了%d位同学的成绩输入\n", n);
	return &head;
}

void output_information(grap head)
{
	grap p = head;
	while(p->next)
	{
		p = p->next;
		printf("%s %s %d %d %d %d\n", p->stu_num, p->name, p->eng, p->mat, p->phy, p->c);
	}
	return;
}

void change_grades(grap head)
{
	int cho, chan;
	char num[20], name1[20];
	scanf("%s%d", num, &cho);
	if (cho)scanf("%d", &chan);
	else scanf("%s", name1);
	grap p = head;
	while (p->next)
	{
		p = p->next;
		if (strcmp(num, p->stu_num) == 0)
		{
			if (cho == 0)strcpy(p->name, name1);
			else if (cho == 1)p->eng = chan;
			else if (cho == 2)p->mat = chan;
			else if (cho == 3)p->phy = chan;
			else p->c = chan;
			printf("%s %s %d %d %d %d", p->stu_num, p->name, p->eng, p->mat, p->phy, p->c);
			break;
		}
	}
	return;
}

void calculate_grade(grap head,int cho)
{
	int sum;
	float ave;
	grap p = head;
	while (p->next)
	{
		p = p->next;
		sum = p->sum;
		ave = sum / 4.0;
		if (cho == 4) printf("%s %s %.2f\n", p->stu_num, p->name, ave);
		else printf("%s %s %d %.2f\n", p->stu_num, p->name, sum, ave);
	}
	return;
}

void select_sort(grap head, int con)
{
	if (head->next == NULL || (head->next)->next == NULL)return;

	grap headp=NULL, tailp=NULL, p, pm, pr;
	int max, min;
	while (head->next)
	{
		p = pr = pm = head;
		max = min = (head->next)->sum;
		while (p->next)
		{
			if (p != head)pr = pr->next;
			p = p->next;
			if (con == 0 && p->sum < min)
			{
				min = p->sum;
				pm = pr;
			}
			if (con == 1 && p->sum > max)
			{
				max = p->sum;
				pm = pr;
			}
		}
		if (headp == NULL)headp = tailp = pm->next;
		else 
		{
			tailp->next = pm->next;
			tailp = pm->next;
		}
		pr = pm->next;
		pm->next = pr->next;
	}
	tailp->next = NULL;
	head->next = headp;
	
	calculate_grade(head, 4);
	return;
}

void bubble_sort(grap head, int con)
{
	if (head->next == NULL && (head->next)->next == NULL)return;

	grap tail = NULL, pre = head, cur = pre->next, next = cur->next;
	while (1)
	{
		grap pre = head, cur = pre->next, next = cur->next;
		while (1)
		{
			if ((con == 0 && cur->sum > next->sum) || (con == 1 && cur->sum < next->sum))
			{
				pre->next = cur->next;
				cur->next = next->next;
				next->next = cur;
				cur = next;
				next = next->next;
			}
			if (next->next == tail)break;

			pre = cur;
			cur = next;
			next = next->next;
		}
		if (pre == head && next->next == tail)break;

		tail = next;
	}
	calculate_grade(head, 4);
	return;
}

void destroy(grap head)
{
	grap p = head;
	while (head->next)
	{
		p = head->next;
		head->next = p->next;
		free(p);
	}
	return;
}

int main(void)
{
	int cho, n, sta, con;
	grap table = NULL;
	do
	{
		scanf("%d", &cho);
		switch (cho)
		{
		case 0:
			if (table != NULL)destroy(table);
			break;
		case 1:
			table = input_grades(&n);
			break;
		case 2:
			output_information(table);
			break;
		case 3:
			change_grades(table);
			break;
		case 4:
			calculate_grade(table, 4);
			break;
		case 5:
			calculate_grade(table, 5);
			break;
		case 6:
			scanf("%d%d", &sta, &con);
			if (con) 
				bubble_sort(table, sta);
			else
				select_sort(table, sta);
			break;
		default:
			break;
		}
	} while (cho != 0);

	return 0;
}
