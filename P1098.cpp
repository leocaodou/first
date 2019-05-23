#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
using namespace std;
int main()
{
	int p1,p2,p3,j,i;
	cin >> p1 >> p2 >> p3;
	string a;
	cin >> a;
	for(i = 0; i < a.length(); i++)
	{
		if(a[i] == '-' && a[i - 1] != '-')
		{
				if(a[i - 1] >= a[i + 1])
				{
					cout << '-' << a[i + 1];
					i = i + 1;
				}
				else
				{
					for(j = 0; j < a[i + 1] - a[i - 1] - 1;j++)
					{
						if(p1 == 3)
							cout << '*';
						if(p1 == 1)
						{
							if(p3 == 1)
							{
								for(int k = 1;k <= p2;k++)
								{
									if(a[i - 1] + j + 1 >= 65 && a[i - 1] + j + 1 <= 90)
									{
										char c = a[i - 1] + j + 1 + 32;
										cout << c;
									}
									else
									{
										char c = a[i - 1] + j + 1;
										cout << c;
									}
								}
							}
							if(p3 == 2)
							{
								for(int k = 1;k <= p2;k++)
								{
									if(a[i + 1] - j - 1 >= 65 && a[i + 1] - j - 1 <= 90)
									{
										char c = a[i + 1] - j - 1 + 32;
										cout << c;
									}
									else
									{
										char c = a[i + 1] - j - 1;
										cout << c;
									}
								}
							}
						}
						if(p1 == 2)
						{
							if(p3 == 1)
							{
								for(int k = 1;k <= p2;k++)
								{
									if(a[i - 1] + j + 1 >= 97 && a[i - 1] + j + 1 <= 122)
									{
										char c = a[i - 1] + j + 1 - 32;
										cout << c;
									}
									else
									{
										char c = a[i - 1] + j + 1;
										cout << c;
									}
								}
							}
							if(p3 == 2)
							{
								for(int k = 1;k <= p2;k++)
								{
									if(a[i + 1] - j - 1 >= 97 && a[i + 1] - j - 1 <= 122)
									{
										char c = a[i + 1] - j - 1 - 32;
										cout << c;
									}
									else
									{
										char c = a[i + 1] - j - 1;
										cout << c;
									}
								}
							}
						}
					}
					cout << a[i + 1];
					i = i + 1;
				}
				continue;
		}
		if(a[i + 1] != '-')
			cout << a[i];
		else
		{
			if(a[i] >= a[i + 2] || (!(a[i] >= 48 &&a[i + 2] <= 57)&&!(a[i] >= 65 &&a[i + 2] <= 90)&&!(a[i] >= 97 &&a[i + 2] <= 122)))
			{
				cout << a[i] << '-' << a[i + 2];
				i = i + 2;
			}
			else
			{
				cout << a[i];
				for(j = 0; j < a[i + 2] - a[i] - 1;j++)
				{
					if(p1 == 3)
						cout << '*';
					if(p1 == 1)
					{
						if(p3 == 1)
						{
							for(int k = 1;k <= p2;k++)
							{
								if(a[i] + j + 1 >= 65 && a[i] + j + 1 <= 90)
								{
									char c = a[i] + j + 1 + 32;
									cout << c;
								}
								else
								{
									char c = a[i] + j + 1;
									cout << c;
								}
							}
						}
						if(p3 == 2)
						{
							for(int k = 1;k <= p2;k++)
							{
								if(a[i + 2] - j - 1 >= 65 && a[i + 2] - j - 1 <= 90)
								{
									char c = a[i + 2] - j - 1 + 32;
									cout << c;
								}
								else
								{
									char c = a[i + 2] - j - 1;
									cout << c;
								}
							}
						}
					}
					if(p1 == 2)
					{
						if(p3 == 1)
						{
							for(int k = 1;k <= p2;k++)
							{
								if(a[i] + j + 1 >= 97 && a[i] + j + 1 <= 122)
								{
									char c = a[i] + j + 1 - 32;
									cout << c;
								}
								else
								{
									char c = a[i] + j + 1;
									cout << c;
								}
							}
						}
						if(p3 == 2)
						{
							for(int k = 1;k <= p2;k++)
							{
								if(a[i + 2] - j - 1 >= 97 && a[i + 2] - j - 1 <= 122)
								{
									char c = a[i + 2] - j - 1 - 32;
									cout << c;
								}
								else
								{
									char c = a[i + 2] - j - 1;
									cout << c;
								}
							}
						}
					}
				}
				cout << a[i + 2];
				i = i + 2;
			}
		}
	}
	return 0;
}
