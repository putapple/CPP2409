#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> movie_titles;
vector<double> movie_ratings;

// 영화 제목, 점수 벡터에 넣는 함수
void addMovie(const string& title, double rating) {
    movie_titles.push_back(title);
    movie_ratings.push_back(rating);
}

// 벡터에 넣은 영화 정보를 출력하는 함수
void printMovies() {
    for (int i = 0; i <movie_titles.size(); ++i ) {
        cout << movie_titles[i] << " : " << movie_ratings[i] << endl;
    }
}

//위에서 만든 함수를 호출하여 영화 정보 출력
int main() {
    addMovie("titinic",9.9);
    addMovie("gone with the wind", 9.6);
    addMovie("terminator", 9.7);

    printMovies();
    return 0;
}