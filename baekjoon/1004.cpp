#include<bits/stdc++.h>
using namespace std;
#define loop(i,n) for(int i=0;i<n;++i)

int main()
{
	cin.tie(NULL), cout.tie(NULL);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t-- > 0) {
		int x1, y1, x2, y2, n;
		cin >> x1 >> y1 >> x2 >> y2 >> n;
		int ans = 0;
		while (n-- > 0) {
			int a, b, r;
			cin >> a >> b >> r;	// �߽� (a,b) ������ r
			// F1 : ������� �� ���ο� ���°�?
			// F2 : �������� ...
			bool F1 = false, F2 = false;
			if (r * r > (a - x1)* (a - x1) + (b - y1) * (b - y1)) F1 = true;
			if (r * r > (a - x2)* (a - x2) + (b - y2) * (b - y2)) F2 = true;
			// �� �� �ϳ��� ���Ե� ��� ������ �� ���� ����ؾ� �Ѵ�.
			if ((F1 && !F2) || (!F1 && F2)) ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}