#include<vector>
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;

// Using this function to find an element 
bool finde(vector<int> vec, int e);

// This function prints the path using x's and o's
vector<vector<int>> printpath(int nodes, vector<vector<int>> mazey, const vector<int> &path);

 // This function uses a DFS algorithm designed by me in order to find 
 // a path from room 0 to room 15
vector<int> findpath(int nodes, vector<vector<int>>& vec);

//
int main() {
try{
	string filename;
	cout << "Enter the file name (e.g.: filename.txt): ";
	while(cin >> filename){
		ifstream infile(filename);
		if (infile.fail()){
			cout << "input error. Enter the file name (e.g.: filename.txt): \n";
			ifstream infile(filename);
		}
		if (!infile.fail()) {
			int chk;
			ifstream infile(filename);
			infile >> chk;
			int check = (int)sqrt((double)chk);
			if (chk != check*check) {
				printf("Room number is not a perfect square.\n");
				printf("Enter the file name with a perfect square room count (e.g.: filename.txt): \n");
				infile.close();
			}
			else break;
		}
	}
			// writing an output file in text format
			ofstream outfile;
			outfile.open("mazedata.txt");
			ifstream infile(filename);
			int N, E, S, W;
			vector<vector<int>> vec;
			int i = 0;
			int j = 0;
			int nodes;
			/////
			infile >> nodes;
			vec.resize(nodes,vector<int> (nodes)); 	
			outfile << "The entered text file: \n";
			while (infile >> N >> E >> S >> W){
				outfile << N << E << S << W << endl;
				if (N==1)
					vec[i-sqrt(nodes)][j] = 1;
				if (E==1)
					vec[i+1][j] = 1;
				if (S==1)
					vec[i+sqrt(nodes)][j] = 1;
				if (W==1)
					vec[i-1][j] = 1;
				j++;
				i++;
			} 
			/////
			cout << "File successfully open\n";
		 	int state;
				cout << "............MENU.............\n";
				cout << " 1 - Print The Adjacency List/Matrix for graph\n";
				cout << " 2 - Find the Length of the Entry-Exit path\n";
				cout << " 3 - Print Out Room Numbers on Entry-Exit path\n";
				cout << " 4 - Exit\n";
	
			while (cin >> state){
					//______________________________________________________________
					if (state == 1){
					// This will print the adjacency matrix
					outfile << endl << "The adjacency matrix of " << nodes << " nodes is: " << endl << endl;
					cout << endl << "The adjacency matrix of " << nodes << " nodes is: " << endl <<endl;	
					for (int i = 0; i<nodes; i++){
						for (int j = 0; j<nodes; j++){
							outfile << vec[i][j] << " ";
							cout << vec[i][j] << " ";
						} 
						outfile << endl;
						cout<<  endl;
					} 
					cout << '\n';
					}
					//________________________________________________________________
					if (state == 2){
					vector<int> v;
					v = findpath(nodes, vec);
					// for the output cmd line
					for (int n = 0; n<v.size(); n++)
							cout << v[n] << ' ';
					cout << "\n\nLength of Entry-Exit path is " << v.size() << ".\n\n";
					// for the output text file
					outfile << "\nPath is: \n";
					for (int i = 0; i < v.size(); i++)
						outfile << v[i] << ' ' ;
					outfile << "\nLength of path is: " << v.size() << '\n';
					}
					//________________________________________________________________
					if (state == 3){
					// create a vector of vector for printing the maze solution
					vector<int> v;
					v = findpath(nodes, vec);
					vector<vector<int>> mazey;	
					mazey.resize(sqrt(nodes), vector<int>(sqrt(nodes)));
					printpath(nodes, mazey, findpath(nodes,vec)) ;
//...................................................................................
					outfile << "The path is: " << endl <<endl;
					int iter = 0;
					for (int i = 0; i < sqrt(nodes); i++){
						for (int j = 0; j < sqrt(nodes); j++){
							mazey[i][j] = iter;
							if (finde(v,iter) == false){
								outfile << 'x' << " ";
							}
							if (finde(v,iter) == true){
								outfile << 'o' << " ";
							}
								iter++;				
						}
						outfile << endl;
					}
//...................................................................................
					
					
					}
					//________________________________________________________________
					if (state == 4){
						break; // Exit button
					}
					//________________________________________________________________
					if ((typeid(state) == typeid(char)) || state>4 || state <0){
						cout << "Woops! Type an integer in 1-4\n";
					}
				
				cout << "............MENU.............\n";
				cout << " 1 - Print The Adjacency List/Matrix for graph\n";
				cout << " 2 - Find the Length of the Entry-Exit path\n";
				cout << " 3 - Print Out Room Numbers on Entry-Exit path\n";
				cout << " 4 - Exit\n";				
			}
	outfile.close();
	infile.close();
	
	return 0;
	}

catch (exception& e)
{
	cerr << "error: " << e.what() << '\n';
	return 1; // 1 indicates failure
}
catch(...)
{
	cerr<< "Oops: unknown exception!\n";
	return 2; // 2 indicates failure
}
}
// ................Quick find function.......................
bool finde(vector<int> vec, int e){
	if (find(vec.begin(), vec.end(), e) != vec.end())
		return true;
	else
		return false;
}
// ......................DFS.................................
vector<int> findpath(int nodes, vector<vector<int>>& vec){
	cout <<  endl;
	cout << "The path from room 0 to room 15 is: " << endl <<endl;
	vector<int> vectori;						// check if visited
	vector<int> path;							// put path
	int j = 0;
	int i = 0;
	path.push_back(0);							// initialize the first node
	vectori.push_back(0);						// debugging vector (ignore)
	while ((i != nodes-1)){						// This while loop implements DFS
		if (vec[i][j] == 1){					// if there is an edge
			if (finde(path, j) == true){		// if edge is already been visited
				j++;							// go to next number in adj list
			}
 			else if (finde(path, j) == false){	// if edge has not been visited
				vectori.push_back(i);			//
				path.push_back(j);				// add edge to path
				i = j;							// set edge equal to i
				j = 0;							// reset edge back to zero for more
			} 									// checking
		}	
		else if ((j == nodes)){					// if edge = 15 rooms
			j = 1 + path[path.size()-1];		// set edge to the second to last index in path
			path.pop_back();					// remove the last index (edge) in path 
			i = path[path.size()-1];			// set i to the last index in path
			vectori.pop_back();					// debugging vector (ignore)
		} 
		else j++;								// if vec[i][j] is 0, go to next edge value
			
	}
	// Print the path found
/* 	for (int n = 0; n<path.size(); n++)
		cout << path[n] << ' ';
	cout << "\n\nLength of Entry-Exit path is " << path.size() << ".\n\n"; */
	return path;
}
// .................... Prints path ..........................
// ................Looks like x's and o's.....................
vector<vector<int>> printpath(int nodes, vector<vector<int>> mazey, const vector<int> &path){
	 cout << "The path is: " << endl <<endl;
	 int iter = 0;
	 for (int i = 0; i < sqrt(nodes); i++){
		 for (int j = 0; j < sqrt(nodes); j++){
			mazey[i][j] = iter;
			if (finde(path,iter) == false){
				cout << 'x' << " ";
			}
			if (finde(path,iter) == true){
				cout << 'o' << " ";
			}
				iter++;				
		}
		cout << endl;
	 }
	 return mazey;
 }
 
