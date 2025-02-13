#include <iostream>
#include <stack>
#include <vector>


using namespace std;

//미로 탐색에 사용할 좌표 구조체.
struct Location2D
{
	Location2D(int row = 0, int col = 0)
		:row(row), col(col)
	{
	}

	int row;//행
	int col;//열
};

//맵 배열.
int mapSize = 0;
std::vector<std::vector<char>> map;
//{
//	{'1','1','1','1','1','1'},
//	{'e','0','1','0','0','1'},
//	{'1','0','0','0','1','1'},
//	{'1','0','1','0','1','1'},
//	{'1','0','1','0','0','x'},
//	{'1','1','1','1','1','1'}
//};

//이동 가능 여부 판단 함수.
bool IsValidLocation(int row, int col)
{
	if (row < 0 || row >= mapSize ||col < 0 || col >= mapSize)
	{
		return false;
	}

	return map[row][col] == '0' || map[row][col] == 'x';
}

bool ParseMap()
{
	FILE* file;
	fopen_s(&file, "../Assets/MapData.txt", "r");

	if (file)
	{
		//첫줄 읽기.
		char buffer[256] = { };
		if (!fgets(buffer, 256, file))
		{
			fclose(file);
			return false;
		}

		//맵 크기 설정.
		sscanf_s(buffer, "size %d", &mapSize);

		//줄 데이터 저장을 위한 임시 배열 선언.
		std::vector<char> line;
		line.reserve(mapSize);

		//맵 데이터 해성을 위한 루프.
		while (fgets(buffer, 256, file))
		{
			//첫칸 처리
			char* context = nullptr;
			char* splitString = strtok_s(buffer, ",", &context);

			if (splitString)
			{
				line.emplace_back(splitString[0]);
			}

			//둘째 부터는 루프.
			while (context)
			{
				splitString = strtok_s(nullptr, ",", &context);
				if (!splitString)
				{
					break;
				}
				
				line.emplace_back(splitString[0]);
			}

			//처리된 라인 데이터를 맵에 추가.
			map.emplace_back(line);
			line.clear();
		}

		fclose(file);
		return true;
	}

	return false;


}

//시작 지점 검색 함수.
void FindStartLocation(int& row, int& col)
{
	
	for (int i = 0; i < mapSize; ++i)
	{
		for (int j = 0; j < mapSize; ++j)
		{
			std::cout << map[i][j] << " ";

			//시작 지점을 나타내는 문자 검색.
			if (map[i][j] == 'e')
			{
				row = i;
				col = j;
				//return;
			}
		}

		std::cout << "\n";
	}
}

//미로 탈출 함수.
void EscapeMaze()
{
	//맵 크기 확인.
	//mapSize = (int)map.size();

	//위치 저장을 위한 변수 선언,
	int row = 0;
	int col = 0;

	//탐색 시작을 위해 시작 위치 찾기.
	FindStartLocation(row, col);

	//스택 서언.
	std::stack<Location2D> stack;
	//탐색 시작을 위해 시작 위치 스택에 삽입.
	stack.push(Location2D(row, col));

	//미로 탐색.
	while (!stack.empty())
	{
		//현재 뒤치 반환.
		Location2D current = stack.top();
		stack.pop();

		//탐색 위치 출력.
		std::cout << "(" << current.row << "," << current.col << ") ";

		row = current.row;
		col = current.col;

		//탈출 조건 확인.
		if (map[row][col] == 'x')
		{
			cout << "\n 미로탐색 성공 \n";
			return;
		}

		//탐색 진행.
		//방문한 현재 위치는 재방문 방지를 위해 표시.
		map[row][col] = '.';

		//상,하,좌,우  위치중 이동 가능한 위치를 스택에 삽입.

		if (IsValidLocation(current.row - 1, current.col))
		{
			stack.push(Location2D(current.row - 1, current.col));
		}
		if (IsValidLocation(current.row + 1, current.col))
		{
			stack.push(Location2D(current.row + 1, current.col));

		}
		if (IsValidLocation(current.row, current.col -1))
		{
			stack.push(Location2D(current.row, current.col -1));
		}
		if (IsValidLocation(current.row, current.col + 1))
		{
			stack.push(Location2D(current.row, current.col + 1));
		}
	}

	cout << "\n미로 탐색 실패\n";

}

int main()
{
	//미로 탐색.
	ParseMap();
	EscapeMaze();

	cin.get();
}