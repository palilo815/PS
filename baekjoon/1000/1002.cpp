#include<bits/stdc++.h>
using namespace std;
#define loop(i,n) for(int i=0;i<n;++i)
#define eps 1e-9	// ��ȿ ����

int main()
{
	cin.tie(NULL), cout.tie(NULL);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	double x1, x2, y1, y2, r1, r2;
	while (t-- > 0) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		// case 1 : ���� ��ġ
		if (x1 == x2 && y1 == y2 && r1 == r2) {
			cout << "-1" << '\n';
			continue;
		}

		// d : (x1,y1) ~ (d2,y2) distance
		// small_r, large_r
		double d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
		double s_r = min(r1, r2), l_r = max(r1, r2);
		int ans;

		// case 2 : �� ���� �ٸ� ���� ����
		if (d + s_r - l_r < eps) {
			// ���Ѵ�
			if (d + s_r - l_r > -eps)
				ans = 1;
			// ������ ������ ������ ����
			else
				ans = 0;
		}
		// case 3 : �ٸ� �� ��
		else {
			// ���Ѵ�
			if (fabs(s_r + l_r - d) < eps)
				ans = 1;
			// ������ ����
			else if (d - s_r - l_r > eps)
				ans = 0;
			// �� �̿� : �� ������ ����
			else
				ans = 2;
		}
		cout << ans << '\n';
	}
	return 0;
}