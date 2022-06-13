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
  cout << "For this program the commands are:\n"
       << "AV to add a vertex\n"
       << "AE to add a edge\n"
       << "RV to remove a vertex\n"
       << "RE to remove a edge\n"
       << "SP to find shortest path\n"
       << "PRINT to print\n"
       << "QUIT to exit the program"
       << endl;
  while (stillRunning == true) {
    cout << "Please enter a command:" << endl;
    cin >> input;

    //add vertex
    if (strcmp(input, "AV") == 0) {
      cout << "Enter a label for a vertex (ex: A):"  << endl;
      cin >> vertices[vCount];
      vCount++;
      
    // add edge
    } else if (strcmp(input, "AE") == 0) {
      //vars
      char v1;
      char v2;
      bool used = false;
      bool used2 = false;
      int vIndex1 = 0;
      int vIndex2 = 0;
      int weight = 0;
      
      cout << "Enter the two vertices you want to connect (ex: A B):" << endl;
      cin >> v1;
      cin >> v2;


      //check if vertices are in the matrix
      if (v1 != v2) {
	for (int i = 0; i < vCount; i++) {
	  if (vertices[i] == v1) {
	    used = true;
	    vIndex1 = i;
	  } else if (vertices[i] == v2) {
	    used2 = true;
	    vIndex2 = i;
	  }
	}
      }

      if (used == true && used2 == true) {
	cout << "Enter a weight value:" << endl;
	cin >> weight;
	graph[vIndex1][vIndex2] = weight;
	
      } else {
	cout << "Invalid input" << endl;
      }

      
    //remove vertex
    //https://stackoverflow.com/questions/879603/remove-an-array-element-and-shift-the-remaining-ones
    } else if (strcmp(input, "RV") == 0) {
      bool used = false;
      char v;
      cout << "Enter a vertex to remove" << endl;
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
      
    //remove edge 
    } else if (strcmp(input, "RE") == 0) {
      char v1;
      char v2;
      bool used = false;
      bool used2 = false;
      int vIndex1 = 0;
      int vIndex2 = 0;
      
      cout << "Enter two vertices to remove the edge between them (ex: A B):" << endl;
      cin >> v1;
      cin >> v2;


      //check if vertices are in the matrix
      if (v1 != v2) {
	for (int i = 0; i < vCount; i++) {
	  if (vertices[i] == v1) {
	    used = true;
	    vIndex1 = i;
	  } else if (vertices[i] == v2) {
	    used2 = true;
	    vIndex2 = i;
	  }
	}
      }

      if (used == true && used2 == true) {
	//remove edge
	graph[vIndex1][vIndex2] = 0;
	
      } else {
	cout << "Invalid input" << endl;
      }
      
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
	for (int i = 0; i < vCount; i++) {
	  cout << vertices[i] << "\t";
	  for (int j = 0; j < vCount; j++){
	    cout << graph[j][i] << "\t";
	  }
	  cout << endl;
	}
      }
 
    //shortest path
    } else if (strcmp(input, "SP") == 0) {

    //quit
    } else if (strcmp(input, "QUIT") == 0) {
      stillRunning = false;
    }
  }
  
  return 0;
}
