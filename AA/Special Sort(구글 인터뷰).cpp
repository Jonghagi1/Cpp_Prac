﻿#include<iostream>
#include<stdio.h>
#include<vector>
#include<math.h>
#pragma warning(disable:4996)

using namespace std;


int  main(
)
{
	//freopen("input.txt", "rt", stdin);// "input.txt"

	int n, temp;

	scanf("%d", &n);

	vector<int> arr(n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > 0 && arr[j + 1] < 0)
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}


	return 0;
}