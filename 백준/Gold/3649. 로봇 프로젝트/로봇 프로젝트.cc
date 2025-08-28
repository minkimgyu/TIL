#include <iostream>
        
        
          
          #include <algorithm>
        
        
          
          using namespace std;
        
        
          
          

        
        
          
          int Hole;
        
        
          
          int N;
        
        
          
          int Lego[1000000];
        
        
          
          

        
        
          
          int main() {
        
        
          
          	ios::sync_with_stdio(false);
        
        
          
          	cin.tie(); cout.tie();
        
        
          
          

        
        
          
          	while (cin >> Hole) { // 입력이 있을 때만 반복문 실행
        
        
          
          		Hole *= 10000000; // 나노미터를 기준으로 비교
        
        
          
          		cin >> N;
        
        
          
          		for (int i = 0; i < N; i++) {
        
        
          
          			cin >> Lego[i];
        
        
          
          		}
        
        
          
          		sort(Lego, Lego + N); // 레고 조각을 크기 순으로 정렬
        
        
          
          

        
        
          
          		int left = 0, right = N - 1, sum = 0;
        
        
          
          		while (left < right) {
        
        
          
          			sum = Lego[left] + Lego[right];
        
        
          
          			if (sum < Hole) left++;
        
        
          
          			else if (sum > Hole) right--;
        
        
          
          			else break;
        
        
          
          		}
        
        
          
          

        
        
          
          		if (sum == Hole)
        
        
          
          			cout << "yes " << Lego[left] << " " << Lego[right] << '\n';
        
        
          
          		else
        
        
          
          			cout << "danger\n";
        
        
          
              
        
        
          
          		/*
        
        
          
          		이진 탐색 방법
        
        
          
          		int left = 0, right = 0, sum = 0;
        
        
          
          		for (int i = 0; i < N && Lego[i] <= Hole / 2; i++) {
        
        
          
          			left = i + 1, right = N - 1;
        
        
          
          			while (left <= right) {
        
        
          
          				int mid = (left + right) / 2;
        
        
          
          				sum = Lego[i] + Lego[mid];
        
        
          
          
        
        
          
          				if (sum < Hole) left = mid + 1;
        
        
          
          				else if (sum > Hole) right = mid - 1;
        
        
          
          				else {
        
        
          
          					left = i, right = mid;
        
        
          
          					i = N;
        
        
          
          					break;
        
        
          
          				}
        
        
          
          			}
        
        
          
          		}
        
        
          
          
        
        
          
          		if (sum == Hole)
        
        
          
          			cout << "yes " << Lego[left] << " " << Lego[right] << endl;
        
        
          
          		else
        
        
          
          			cout << "danger" << endl;
        
        
          
          		*/
        
        
          
          	}
        
        
          
          	return 0;
        
        
          
          }
