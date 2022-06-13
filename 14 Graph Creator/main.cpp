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

  while (stillRunning == true) {
    cout << "Please enter: 'ADDVERTEX', 'ADDEDGE', "
	 << "'REMOVEVERTEX', 'REMOVEEDGE', 'PRINT', or 'QUIT'" << endl;
    cin >> input;

    //add vertex
    if (strcmp(input, "ADDVERTEX") == 0) {
      cout << "Enter a label for a vertex (ex: A):"  << endl;
      cin >> vertices[vCount];
      vCount++;
      for (int i = 0; i < vCount; i++) {
	cout << vertices[i] << " ";
      }
      cout << endl;
      
    // add edge
    } else if (strcmp(input, "ADDEDGE") == 0) {
      char v1;
      char v2;
      cout << "Enter the two vertices you want to connect (ex: A B):" << endl;
      cin >> v1;
      cin >> v2;
      bool used = false;
      bool used2 = false;

      //check if vertices are in the matrix
      if (v1 != v2) {
	for (int i = 0; i < vCount; i++) {
	  if (vertices[i] == v1) {
	    used = true;
	  } else if (vertices[i] == v2) {
	    used2 = true;
	  }
	}
      }

      if (used == true && used2 == true) {
	cout << "valid input" << endl;
      }

      
    //remove vertex
    } else if (strcmp(input, "REMOVEVERTEX") == 0) {

      
    //remove edge 
    } else if (strcmp(input, "REMOVEEDGE") == 0) {


      
    //print (Referenced Fiona Wang's code)
    } else if (strcmp(input, "PRINT") == 0) {

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
	for (int i = 0; i < 20; i++) {
	  if (vertices[i] != '\0') {
	    cout << vertices[i] << "\t";
	    for (int j = 0; j < 20; j++){
	      if (j < vCount) {
		cout << graph[j][i] << "\t";
	      }
	    }
	    cout << endl;
	  }
	}
      }
 
    //quit
    } else if (strcmp(input, "QUIT") == 0) {
      stillRunning = false;
    }
  }
  
  return 0;
}
