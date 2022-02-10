#include <stdio.h>
#include <math.h>

/*
	program rozwiazuje problem, obliczajac pole 4 trojkatow
		- trojkata bazowego ABC
		- trojkata ABP
		- trojkata ACP
		- trojkata BCP
	jesli suma pol ABP, ACP i BCP jest równa ABC, to punkt jest zawarty w ABC
	jesli suma nadal jest równa, ale przynajmniej jeden z trojkatow jest równy 0, to punkt lezy na jednym z bokow trojkata
		w przeciwnym razie punkt lezy poza trojkatem
*/

int main()
{
	double x1,x2,x3,x4;
	double y1,y2,y3,y4;
	do
	{
		scanf("%lf",&x1);
		scanf("%lf",&y1);
		scanf("%lf",&x2);
		scanf("%lf",&y2);
		scanf("%lf",&x3);
		scanf("%lf",&y3);
		scanf("%lf",&x4);
		scanf("%lf",&y4);
	
		double trangle_surf = 0.5*fabs((x2-x1)*(y3-y1)-(y2-y1)*(x3-x1));
		double A1 = 0.5*fabs((x2-x1)*(y4-y1)-(y2-y1)*(x4-x1));
		double A2 = 0.5*fabs((x3-x1)*(y4-y1)-(y3-y1)*(x4-x1));
		double A3 = 0.5*fabs((x3-x2)*(y4-y2)-(y3-y2)*(x4-x2));
		
		if(A1 + A2 + A3 == trangle_surf)
		{
			if(A1 == 0 && A2 == 0 && A3 == 0 && x1 == 0)break;
			if(A1 == 0 || A2 == 0 || A3 == 0)printf("E\n");
			else printf("I\n");
		}
		else printf("O\n");
	
	}while(x1!=0||x2!=0||x3!=0||x4!=0||y1!=0||y2!=0||y3!=0||y3!=0);

}
