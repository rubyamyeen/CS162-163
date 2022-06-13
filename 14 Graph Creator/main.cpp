/*
 * This program creates a directed graph with weighted edges that are represented in a adjacency matrix
 * The user can add and remove vertexes and edges. 
 * They will also be able to calculate the shortest path with Dijkstra's algorithm.
 * Author: Ruby Amyeen
 * Date: 6/7/22
 */

#include <iostream>
#include <cstring>

using namespace std;

//function prototypes
int findIndex(char v, char vertices[], int vCount);
int main() {
  //variables
  int graph[20][20];
  char vertices[20];
  int vCount = 0;
  bool stillRunning = true;
  char input[20];

  //emptying the matrix
  for (int i = 0; i < 20; i++) {
    vertices[i] = '\0';
    for (int j = 0; j < 20; j++) {
      graph[i][j] = 0;
    }
  }
  cout << "For this program the commands are:\n"
       << "addV: to add a vertex\n"
       << "addE: to add a edge\n"
       << "removeV: to remove a vertex\n"
       << "removeE: to remove a edge\n"
       << "shortPath: to find shortest path\n"
       << "print: to print\n"
       << "quit: to exit the program\n"
       << endl;
  while (stillRunning == true) {
    cout << "Enter a command: ";
    cin >> input;
    //cout << endl;

    //add vertex
    if (strcmp(input, "addV") == 0) {
      cout << "Enter a label for a vertex (ex: A):" << endl;
      cin >> vertices[vCount];
      vCount++;
      
    // add edge
    } else if (strcmp(input, "addE") == 0) {
      //vars
      char v1;
      char v2;
      int weight = 0;
      
      cout << "Enter the two vertices you want to connect (ex: A B):" << endl;
      cin >> v1;
      cin >> v2;
      
      if (v1 == v2 || findIndex(v1, vertices, vCount) == -1 || findIndex(v2, vertices, vCount) == -1) {
	cout << "Invalid input" << endl;
	
      } else {
	cout << "Enter the weight value:" << endl;
	cin >> weight;
	graph[findIndex(v1, vertices, vCount)][findIndex(v2, vertices, vCount)] = weight;
      }
      
    //remove vertex
    //https://stackoverflow.com/questions/879603/remove-an-array-element-and-shift-the-remaining-ones
    } else if (strcmp(input, "removeV") == 0) {
      bool used = false;
      char v;
      cout << "Enter a vertex to remove:" << endl;
      cin >> v;
      //check if inside the matrix
      for (int i = 0; i < 20; i++) {
	if (vertices[i] == v) {
	  used = true;
	  //shift next element over with vertices
	  for (int j = i; j < vCount; j++) {
	    vertices[j] = vertices[j+1];
	  }
	  //shift for graph
	  for (int k = i; k < vCount; k++) {
	    for (int l = i; l < vCount; l++) {
	      graph[l][k] = graph[l][k + 1];
	    }
	    for (int m = i; m < vCount; m++) {
	      graph[k][m] = graph[k + 1][m];
	    }
	  }
	  vCount--;
	}
      }
      if (used == false) {
	cout << "Invalid input" << endl;
      }
      
    //remove edge 
    } else if (strcmp(input, "removeE") == 0) {
      //vars
      char v1;
      char v2;
      int weight = 0;
      
      cout << "Enter two vertices to remove the edge between them (ex: A B):" << endl;
      cin >> v1;
      cin >> v2;
      
      if (v1 == v2 || findIndex(v1, vertices, vCount) == -1 || findIndex(v2, vertices, vCount) == -1) {
	cout << "Invalid input" << endl;
	
      } else {
	graph[findIndex(v1, vertices, vCount)][findIndex(v2, vertices, vCount)] = 0;
      }
      
      
    //print (Referenced Fiona Wang's code)
    } else if (strcmp(input, "print") == 0) {

      //no vertices
      if (vCount == 0) {
	cout << "Graph is empty!" << endl;;
	
      // print
      } else {
	//prints first row of labels
	for (int i = 0; i < 20; i++){
	  if (vertices[i]){
	    cout << "\t" << vertices[i];
	  }
	}
	cout << endl;
	//prints out the label and its corresponding edges
	for (int i = 0; i < vCount; i++) {
	  cout << vertices[i] << "\t";
	  for (int j = 0; j < vCount; j++){
	    cout << graph[j][i] << "\t";
	  }
	  cout << endl;
	}
      }
 
    //shortest path
    } else if (strcmp(input, "shortPath") == 0) {

    //quit
    } else if (strcmp(input, "quit") == 0) {
      stillRunning = false;
    }
  }
  
  return 0;
}

int findIndex(char v, char vertices[], int vCount) {
  for (int i = 0; i < vCount; i++) {
    if (vertices[i] == v) {
      return i;
    }
  }
  return -1;
}
