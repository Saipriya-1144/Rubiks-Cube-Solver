#include<bits/stdc++.h>
using namespace std;


/*
Store Cube in vector of vector

0 index for top face
1 index for front face
2 index for left face
3 index for down face
4 index for back face
5 index for right face
*/

class cube{
    public:
     vector<vector<int>> rubics_cube;

     void take_input();//takes input into 2d vector
     void print_cube();//prints the cube
     
     void right_face_cw(int r);//rotate right face x times in clock wise direction
     void right_face_acw(int r);//rotate right face x times in Anticlock wise direction
     void left_face_cw(int r);//rotate left face x times in clock wise direction
     void left_face_acw(int r);//rotate right face x times in Anticlock wise direction
     void top_face_cw(int r);//rotate top face x times in clock wise direction
     void top_face_acw(int r);//rotate top face x times in Anticlock wise direction
     void bottom_face_cw(int r);//rotate bottom face x times in clock wise direction
     void bottom_face_acw(int r);//rotate bottom face x times in Anticlock wise direction
     void front_face_cw(int r);//rotate front face x times in clock wise direction
     void front_face_acw(int r);//rotate front face x times in Anticlock wise direction
     void bottom_2layers_cw(int r);//rotate bottom 2 layers x times in clock wise direction
     void bottom_2layers_acw(int r);//rotate bottom 2 layers x times in Anticlock wise direction
     void spin_cw(int r);//spin x times in clock wise direction
     void spin_acw(int r);//spin x times in Anticlock wise direction
     void rotate_upside_down();//rotate cube upside down
     void face_2layers_cw(int r);//rotate front face 2 layers x times in clock wise direction
     void face_2layers_acw(int r);//rotate front face 2 layers x times in Anticlock wise direction

     void bottom_face_plus();//Solving edges in last layer

     void righty_alg(int r);
     void lefty_alg(int r);
     void to_fix_with_righty_alg();
     void bottom_layer_corners();//solving corners in the last layer

     void to_move_edge_right();
     void to_move_edge_left();
     void second_layer_edges(); //solving 2nd layer edges

     int check_form_in_step4();
     void top_layer_plus_step4();//Making plus on top face

     int check_form_in_step5();
     void sqnce_in_step5();
     void position_toplayer_corners();//positioning the top layer corners(corner should be between correct centers)

     void twisting_top_layer_corners(); //solving top layer corners (twisting them after they are correctly positioned)

     void sqnce_for_top_layer_edges();
     int check_form_in_lst_step();
     void top_layer_edges(); //solving top layer edges
};

void cube::print_cube(){ //to print the cube
      cout << "\nTop face of cube:\n";
   for(int i=1;i<=9;i++){
      char x=rubics_cube[0][i]+'a';
      cout << x << " ";
   }

   cout << "\nfront face of cube:\n";
   for(int i=1;i<=9;i++){
      char x=rubics_cube[1][i]+'a';
      cout << x << " ";
   }

   cout << "\nleft face of cube:\n";
   for(int i=1;i<=9;i++){
      char x=rubics_cube[2][i]+'a';
      cout << x << " ";
   }

   cout << "\ndown face of cube:\n";
   for(int i=1;i<=9;i++){
      char x=rubics_cube[3][i]+'a';
      cout << x << " ";
   }

   cout << "\nback face of cube:\n";
   for(int i=1;i<=9;i++){
      char x='a'+rubics_cube[4][i];
      cout << x << " ";
   }

   cout << "\nright face of cube:\n";
   for(int i=1;i<=9;i++){
      char x='a'+rubics_cube[5][i];
      cout << x << " ";
   }

   cout << "\n";
}

void cube::take_input(){ //to take the input
    rubics_cube.resize(6);
    for(int i=0;i<6;i++){
        rubics_cube[i].resize(10);
    }

    char x;
    cout << "give top face of cube:\n";
   for(int i=1;i<=9;i++){
      cin >> x;
      rubics_cube[0][i]=x-'a';
   }
   

   cout << "give front face of cube:\n";
   for(int i=1;i<=9;i++){
      cin >> x;
      rubics_cube[1][i]=x-'a';
   }

   cout << "give left face of cube:\n";
   for(int i=1;i<=9;i++){
      cin >> x;
      rubics_cube[2][i]=x-'a';
   }

   cout << "give down face of cube:\n";
   for(int i=1;i<=9;i++){
      cin >> x;
      rubics_cube[3][i]=x-'a';
   }
  
   cout << "give back face of cube:\n";
   for(int i=1;i<=9;i++){
      cin >> x;
      rubics_cube[4][i]=x-'a';
   }

   cout << "give right face of cube:\n";
   for(int i=1;i<=9;i++){
      cin >> x;
      rubics_cube[5][i]=x-'a';
   }
}

void cube::right_face_cw(int r){// to rotate right face r times in clock wise direction

   if(r==3){
     //write acw once
     right_face_acw(1);
     return;
   }

while(r--){
   for(int j=1;j<=3;j++){
   int x=rubics_cube[0][3*j];

  for(int i=0;i<2;i++){
     int y;
     if(i==1){
        y=i+2;
     }else{
        y=i+1;
     }

     rubics_cube[i][3*j]=rubics_cube[y][3*j];    
  }

   rubics_cube[3][3*j]=rubics_cube[4][10-3*j];
   rubics_cube[4][10-3*j]=x;
 }

 vector<int> v(10);
 int k=1;
 for(int i=2;i>=0;i--){
    for(int j=3;j>=1;j--){
       v[k]=rubics_cube[5][3*j-i];
       k++;
    }
 } 

 for(int i=1;i<=9;i++){
    rubics_cube[5][i]=v[i];
 }
}
}

void cube:: right_face_acw(int r){//To rotate right face r times in Anticlock wise direction
   if(r==3){
      right_face_cw(1);
      return;
   }
   
 while(r--){
   for(int j=1;j<=3;j++){
   int x=rubics_cube[3][3*j];

  for(int i=3;i>=1;i--){
     if(i==2)
     continue;

     int y;
     if(i==3){
        y=i-2;
     }else{
        y=i-1;
     }

     rubics_cube[i][3*j]=rubics_cube[y][3*j];    
  }

   rubics_cube[0][3*j]=rubics_cube[4][10-3*j];
   rubics_cube[4][10-3*j]=x;
 }

 vector<int> v(10);
 int k=1;
 for(int i=0;i<=2;i++){
    for(int j=1;j<=3;j++){
       v[k]=rubics_cube[5][3*j-i];
       k++;
    }
 } 

 for(int i=1;i<=9;i++){
    rubics_cube[5][i]=v[i];
 }
 }

}

void cube::left_face_cw(int r){//To rotate left face r times in clock wise direction
   if(r==3){
      left_face_acw(1);
      return;
   }

 while(r--){ 
 for(int j=1;j<=3;j++){
   int x=rubics_cube[3][3*j-2];

  for(int i=3;i>=1;i--){
     if(i==2)
     continue;

     int y;
     if(i==3){
        y=i-2;
     }else{
        y=i-1;
     }

     rubics_cube[i][3*j-2]=rubics_cube[y][3*j-2];    
  }

   rubics_cube[0][3*j-2]=rubics_cube[4][12-3*j];
   rubics_cube[4][12-3*j]=x;
 }

  vector<int> v(10);
 int k=1;
 for(int i=2;i>=0;i--){
    for(int j=3;j>=1;j--){
       v[k]=rubics_cube[2][3*j-i];
       k++;
    }
 } 

 for(int i=1;i<=9;i++){
    rubics_cube[2][i]=v[i];
 }
}  
}

void cube::left_face_acw(int r){//To rotate left face r times in Anticlock wise direction
   if(r==3){
      left_face_cw(1);
      return;
   }

 while(r--){

  for(int j=1;j<=3;j++){
   int x=rubics_cube[0][3*j-2];

  for(int i=0;i<2;i++){
     int y;
     if(i==1){
        y=i+2;
     }else{
        y=i+1;
     }

     rubics_cube[i][3*j-2]=rubics_cube[y][3*j-2];    
  }

   rubics_cube[3][3*j-2]=rubics_cube[4][12-3*j];
   rubics_cube[4][12-3*j]=x;
 }

 vector<int> v(10);
 int k=1;
 for(int i=0;i<=2;i++){
    for(int j=1;j<=3;j++){
       v[k]=rubics_cube[2][3*j-i];
       k++;
    }
 } 

 for(int i=1;i<=9;i++){
    rubics_cube[2][i]=v[i];
 }
 }

}

void cube::top_face_cw(int r){//To rotate top face r times in clock wise direction
  if(r==3){
     top_face_acw(1);
     return;
  }

  while(r--){

  for(int j=1;j<=3;j++){
   int x=rubics_cube[5][j];

  for(int i=5;i>1;i--){
     if(i==3)
     continue;

     int y;
     if(i==4){
        y=i-2;
     }else{
        y=i-1;
     }

     rubics_cube[i][j]=rubics_cube[y][j];    
  }

   rubics_cube[1][j]=x;
 }

 vector<int> v(10);
 int k=1;
 for(int i=2;i>=0;i--){
    for(int j=3;j>=1;j--){
       v[k]=rubics_cube[0][3*j-i];
       k++;
    }
 } 

 for(int i=1;i<=9;i++){
    rubics_cube[0][i]=v[i];
 }

}
}

void cube::top_face_acw(int r){//To rotate top face r times in Anticlock wise direction
   if(r==3){
     top_face_cw(1);
     return;
  }

 while(r--){

  for(int j=1;j<=3;j++){
   int x=rubics_cube[1][j];

  for(int i=1;i<5;i++){
     if(i==3)
     continue;

     int y;
     if(i==2){
        y=i+2;
     }else{
        y=i+1;
     }

     rubics_cube[i][j]=rubics_cube[y][j];    
  }

   rubics_cube[5][j]=x;
 }

 vector<int> v(10);
 int k=1;
 for(int i=0;i<=2;i++){
    for(int j=1;j<=3;j++){
       v[k]=rubics_cube[0][3*j-i];
       k++;
    }
 } 

 for(int i=1;i<=9;i++){
    rubics_cube[0][i]=v[i];
 }
}
}

void cube::bottom_face_cw(int r){//To rotate bottom face r times in clock wise direction
  if(r==3){
     bottom_face_acw(1);
     return;
  }

while(r--){
  for(int j=1;j<=3;j++){
   
   int z=rubics_cube[5][6+j];

  for(int i=5;i>1;i--){
     if(i==3)
     continue;

     int y;
     if(i==4){
        y=i-2;
     }else{
        y=i-1;
     }
 
     rubics_cube[i][6+j]=rubics_cube[y][6+j];
  }

   rubics_cube[1][j+6]=z;
 }

 vector<int> v(10);
 int k=1;
 for(int i=0;i<=2;i++){
    for(int j=1;j<=3;j++){
       v[k]=rubics_cube[3][3*j-i];
       k++;
    }
 } 

 for(int i=1;i<=9;i++){
    rubics_cube[3][i]=v[i];
 }
}
}

void cube::bottom_face_acw(int r){//To rotate bottom face r times in Anticlock wise direction
  if(r==3){
     bottom_face_cw(1);
     return;
  }

 while(r--){
     
  for(int j=1;j<=3;j++){

   int z=rubics_cube[1][6+j];
  for(int i=1;i<5;i++){
     if(i==3)
     continue;

     int y;
     if(i==2){
        y=i+2;
     }else{
        y=i+1;
     }

     rubics_cube[i][6+j]=rubics_cube[y][6+j];    
  }

   rubics_cube[5][6+j]=z;
 }

 vector<int> v(10);
 int k=1;
 for(int i=2;i>=0;i--){
    for(int j=3;j>=1;j--){
       v[k]=rubics_cube[3][3*j-i];
       k++;
    }
 } 

 for(int i=1;i<=9;i++){
    rubics_cube[3][i]=v[i];
 }
}
}

void cube::front_face_cw(int r){//To rotate front face r times in clock wise direction
 if(r==3){
    front_face_acw(1);
    return;
 }

 while(r--){
 vector<int> w;

   for(int i=7;i<10;i++){
      w.push_back(rubics_cube[0][i]);
   }
   for(int i=0;i<3;i++){
      w.push_back(rubics_cube[5][3*i+1]);
   }
   for(int i=3;i>0;i--){
      w.push_back(rubics_cube[3][i]);
   }
   for(int i=3;i>0;i--){
      w.push_back(rubics_cube[2][3*i]);
   }

   int x=w[11],y=w[10],z=w[9];
   for(int i=11;i>=3;i--){
       w[i]=w[i-3];
   }
   w[0]=z;
   w[1]=y;
   w[2]=x;

   int p=0;
   for(int i=7;i<10;i++){
      rubics_cube[0][i]=w[p];
      p++;
   }
   for(int i=0;i<3;i++){
      rubics_cube[5][3*i+1]=w[p];
      p++;
   }
   for(int i=3;i>0;i--){
      rubics_cube[3][i]=w[p];
      p++;
   }
   for(int i=3;i>0;i--){
      rubics_cube[2][3*i]=w[p];
      p++;
   }

   vector<int> v(10);
 int k=1;
 for(int i=2;i>=0;i--){
    for(int j=3;j>=1;j--){
       v[k]=rubics_cube[1][3*j-i];
       k++;
    }
 } 

 for(int i=1;i<=9;i++){
    rubics_cube[1][i]=v[i];
 }
 }
}

void cube::front_face_acw(int r){//To rotate front face r times in Anticlock wise direction
  if(r==3){
    front_face_cw(1);
    return;
 }

 while(r--){
 vector<int> w;

   for(int i=7;i<10;i++){
      w.push_back(rubics_cube[0][i]);
   }
   for(int i=0;i<3;i++){
      w.push_back(rubics_cube[5][3*i+1]);
   }
   for(int i=3;i>0;i--){
      w.push_back(rubics_cube[3][i]);
   }
   for(int i=3;i>0;i--){
      w.push_back(rubics_cube[2][3*i]);
   }

   int x=w[0],y=w[1],z=w[2];
   for(int i=0;i<9;i++){
       w[i]=w[i+3];
   }
   w[9]=x;
   w[10]=y;
   w[11]=z;

   int p=0;
   for(int i=7;i<10;i++){
      rubics_cube[0][i]=w[p];
      p++;
   }
   for(int i=0;i<3;i++){
      rubics_cube[5][3*i+1]=w[p];
      p++;
   }
   for(int i=3;i>0;i--){
      rubics_cube[3][i]=w[p];
      p++;
   }
   for(int i=3;i>0;i--){
      rubics_cube[2][3*i]=w[p];
      p++;
   }

  vector<int> v(10);
 int k=1;
 for(int i=0;i<=2;i++){
    for(int j=1;j<=3;j++){
       v[k]=rubics_cube[1][3*j-i];
       k++;
    }
 } 

 for(int i=1;i<=9;i++){
    rubics_cube[1][i]=v[i];
 }
}
}

void cube::bottom_2layers_cw(int r){//To rotate bottom 2 layers r times in clock wise direction
   if(r==3){
      bottom_2layers_acw(1);
      return;
   }

   while(r--){
   for(int j=1;j<=3;j++){
   int x=rubics_cube[5][3+j];
   int z=rubics_cube[5][6+j];

  for(int i=5;i>1;i--){
     if(i==3)
     continue;

     int y;
     if(i==4){
        y=i-2;
     }else{
        y=i-1;
     }

     rubics_cube[i][3+j]=rubics_cube[y][3+j];   
     rubics_cube[i][6+j]=rubics_cube[y][6+j];
  }

   rubics_cube[1][j+3]=x;
   rubics_cube[1][j+6]=z;
 }

 vector<int> v(10);
 int k=1;
 for(int i=0;i<=2;i++){
    for(int j=1;j<=3;j++){
       v[k]=rubics_cube[3][3*j-i];
       k++;
    }
 } 

 for(int i=1;i<=9;i++){
    rubics_cube[3][i]=v[i];
 }
  
 }
}

void cube::bottom_2layers_acw(int r){//To rotate bottom 2 layers r times in Anticlock wise direction
   if(r==3){
      bottom_2layers_cw(1);
      return;
   }

   while(r--){

   for(int j=1;j<=3;j++){
   int x=rubics_cube[1][3+j];
   int z=rubics_cube[1][6+j];
  for(int i=1;i<5;i++){
     if(i==3)
     continue;

     int y;
     if(i==2){
        y=i+2;
     }else{
        y=i+1;
     }

     rubics_cube[i][3+j]=rubics_cube[y][3+j]; 
     rubics_cube[i][6+j]=rubics_cube[y][6+j];    
  }

   rubics_cube[5][3+j]=x;
   rubics_cube[5][6+j]=z;


 }

 vector<int> v(10);
 int k=1;
 for(int i=2;i>=0;i--){
    for(int j=3;j>=1;j--){
       v[k]=rubics_cube[3][3*j-i];
       k++;
    }
 } 

 for(int i=1;i<=9;i++){
    rubics_cube[3][i]=v[i];
 }

 }
}

void cube::spin_cw(int r){//To spin cube r times in clock wise direction
   if(r==3){
      spin_acw(1);
      return;
   }

   bottom_2layers_cw(r);
   top_face_cw(r);
}

void cube::spin_acw(int r){//To spin cube r times in Anticlock wise direction
   if(r==3){
      spin_cw(1);
      return;
   }

   bottom_2layers_acw(r);
   top_face_acw(r);
}

void cube::face_2layers_cw(int r){//To rotate face 2 layers r times in clock wise direction
   if(r==3){
      face_2layers_acw(1);
      return;
   }

   while(r--){
    vector<int> w,u;

   for(int i=7;i<10;i++){
      w.push_back(rubics_cube[0][i]);
      u.push_back(rubics_cube[0][i-3]);
   }
   for(int i=0;i<3;i++){
      w.push_back(rubics_cube[5][3*i+1]);
      u.push_back(rubics_cube[5][3*i+2]);
   }
   for(int i=3;i>0;i--){
      w.push_back(rubics_cube[3][i]);
      u.push_back(rubics_cube[3][i+3]);
   }
   for(int i=3;i>0;i--){
      w.push_back(rubics_cube[2][3*i]);
      u.push_back(rubics_cube[2][3*i-1]);
   }

   int x=w[11],y=w[10],z=w[9],x1=u[11],y1=u[10],z1=u[9];
   for(int i=11;i>=3;i--){
       w[i]=w[i-3];
       u[i]=u[i-3];
   }
   w[0]=z;
   u[0]=z1;
   w[1]=y;
   u[1]=y1;
   w[2]=x;
   u[2]=x1;

   int p=0;
   for(int i=7;i<10;i++){
      rubics_cube[0][i]=w[p];
      rubics_cube[0][i-3]=u[p];
      p++;
   }
   for(int i=0;i<3;i++){
      rubics_cube[5][3*i+1]=w[p];
      rubics_cube[5][3*i+2]=u[p];
      p++;
   }
   for(int i=3;i>0;i--){
      rubics_cube[3][i]=w[p];
      rubics_cube[3][i+3]=u[p];
      p++;
   }
   for(int i=3;i>0;i--){
      rubics_cube[2][3*i]=w[p];
      rubics_cube[2][3*i-1]=u[p];
      p++;
   }

   vector<int> v(10);
 int k=1;
 for(int i=2;i>=0;i--){
    for(int j=3;j>=1;j--){
       v[k]=rubics_cube[1][3*j-i];
       k++;
    }
 } 

 for(int i=1;i<=9;i++){
    rubics_cube[1][i]=v[i];
 }
   }
}

void cube::face_2layers_acw(int r){//To rotate face 2 layers r times in Anticlock wise direction
  if(r==3){
      face_2layers_cw(1);
      return;
   }

   while(r--){
      vector<int> w,u;

    for(int i=7;i<10;i++){
      w.push_back(rubics_cube[0][i]);
      u.push_back(rubics_cube[0][i-3]);
   }
   for(int i=0;i<3;i++){
      w.push_back(rubics_cube[5][3*i+1]);
      u.push_back(rubics_cube[5][3*i+2]);
   }
   for(int i=3;i>0;i--){
      w.push_back(rubics_cube[3][i]);
      u.push_back(rubics_cube[3][i+3]);
   }
   for(int i=3;i>0;i--){
      w.push_back(rubics_cube[2][3*i]);
      u.push_back(rubics_cube[2][3*i-1]);
   }

   int x=w[0],y=w[1],z=w[2],x1=u[0],y1=u[1],z1=u[2];
   for(int i=0;i<9;i++){
       w[i]=w[i+3];
       u[i]=u[i+3];
   }
   w[9]=x;
   u[9]=x1;
   w[10]=y;
   u[10]=y1;
   w[11]=z;
   u[11]=z1;

   int p=0;
   for(int i=7;i<10;i++){
      rubics_cube[0][i]=w[p];
      rubics_cube[0][i-3]=u[p];
      p++;
   }
   for(int i=0;i<3;i++){
      rubics_cube[5][3*i+1]=w[p];
      rubics_cube[5][3*i+2]=u[p];
      p++;
   }
   for(int i=3;i>0;i--){
      rubics_cube[3][i]=w[p];
      rubics_cube[3][i+3]=u[p];
      p++;
   }
   for(int i=3;i>0;i--){
      rubics_cube[2][3*i]=w[p];
      rubics_cube[2][3*i-1]=u[p];
      p++;
   }

  vector<int> v(10);
 int k=1;
 for(int i=0;i<=2;i++){
    for(int j=1;j<=3;j++){
       v[k]=rubics_cube[1][3*j-i];
       k++;
    }
 } 

 for(int i=1;i<=9;i++){
    rubics_cube[1][i]=v[i];
 }
   }
}



void cube::rotate_upside_down(){ //to rotate cube upside down
   swap(rubics_cube[0],rubics_cube[3]);
  reverse(rubics_cube[1].begin()+1,rubics_cube[1].end());
  reverse(rubics_cube[4].begin()+1,rubics_cube[4].end());
  swap(rubics_cube[1],rubics_cube[4]);
  reverse(rubics_cube[2].begin()+1,rubics_cube[2].end());
  reverse(rubics_cube[5].begin()+1,rubics_cube[5].end());
}

void cube::righty_alg(int r){
  while(r--){
     right_face_cw(1);
     top_face_cw(1);
     right_face_acw(1);
     top_face_acw(1);
  }
}

void cube::lefty_alg(int r){
   while(r--){
      left_face_acw(1);
      top_face_acw(1);
      left_face_cw(1);
      top_face_cw(1);
   }
}

void cube::bottom_face_plus(){//To solve bottom face edges

   int i;

  for(int k=0;k<=4;k++){
   for(int i=0;i<=4;i++){
      if(rubics_cube[1][6]==rubics_cube[3][5]){
         while(rubics_cube[0][6]==rubics_cube[3][5]){
            top_face_cw(1);
         }

         right_face_cw(1);

      }else if(rubics_cube[1][2]==rubics_cube[3][5] || rubics_cube[1][4]==rubics_cube[3][5] || rubics_cube[1][8]==rubics_cube[3][5]){

         while(rubics_cube[0][8]==rubics_cube[3][5]){
            top_face_cw(1);
         }

         while(rubics_cube[1][6]!=rubics_cube[3][5]){
            front_face_cw(1);
         }

         for(int j=0;j<4;j++){
            if(rubics_cube[0][6]!=rubics_cube[3][5]){
              right_face_cw(1);
              break;
            }else{
              top_face_cw(1);
            }
         }
      }
   }

    spin_cw(1);

  }

   //for taking white edges in bottom face to top
   for(i=0;i<=4;i++){
      if(rubics_cube[3][6]!=rubics_cube[3][5]){
         bottom_face_cw(1);
      }else{
         int j;
         for(j=0;j<4;j++){
            if(rubics_cube[0][6]!=rubics_cube[3][5]){
              right_face_cw(2);
              break;
            }else{
              top_face_cw(1);
            }
         }
      }
   }
   
   
   for(int i=0;i<4;i++){
   while(rubics_cube[1][2]!=rubics_cube[1][5]){
      bottom_2layers_cw(1);
   }

   front_face_cw(2);
   spin_cw(1);
  }
   
}

void cube::to_fix_with_righty_alg(){
   while(rubics_cube[1][9]!=rubics_cube[1][5] || rubics_cube[5][7]!=rubics_cube[5][5] || rubics_cube[3][3]!=rubics_cube[3][5]){
       righty_alg(1);
   }
}

void cube::bottom_layer_corners(){//to solve bottom layer corners
   int t=8;
   while(t--){
      //checking if top right corner has white
      int l=0,r=0,c=0,x,y;

      if(rubics_cube[0][9]==rubics_cube[3][5] || rubics_cube[1][3]==rubics_cube[3][5] || rubics_cube[5][1]==rubics_cube[3][5]){
         if(rubics_cube[0][9]==rubics_cube[3][5]){
            x=rubics_cube[1][3];
            y=rubics_cube[5][1];
         }else if(rubics_cube[1][3]==rubics_cube[3][5]){
            x=rubics_cube[0][9];
            y=rubics_cube[5][1];
         }else{
            x=rubics_cube[0][9];
            y=rubics_cube[1][3];
         }

         if(x==rubics_cube[1][5] || y==rubics_cube[1][5] || x==rubics_cube[5][5] || y==rubics_cube[5][5]){
            if(x==rubics_cube[1][5] && y!=rubics_cube[5][5]){
               bottom_2layers_acw(1);
               //right a code for fixing the given piece in its correct position
               to_fix_with_righty_alg();
            }
            else if(y==rubics_cube[1][5] && x!=rubics_cube[5][5]){
               bottom_2layers_acw(1);
               //right a code for fixing the given piece in its correct position
               to_fix_with_righty_alg();

            }else if(x==rubics_cube[5][5] && y!=rubics_cube[1][5]){
               bottom_2layers_cw(1);
               //right a code for fixing the given piece in its correct position
               to_fix_with_righty_alg();

            }else if(y==rubics_cube[5][5] && x!=rubics_cube[1][5]){
               bottom_2layers_cw(1);
               //right a code for fixing the given piece in its correct position
               to_fix_with_righty_alg();

            }else{
               //right a code for fixing the given piece in its correct position
               to_fix_with_righty_alg();

            }
         }else{
            bottom_2layers_acw(2);
            //right a code for fixing the given piece in its correct position
            to_fix_with_righty_alg();
         }
      }else{
         top_face_cw(1);
      }
   }

   //verifying if bottom layer corners are properly placed

   //to solve pieces in bottom layer that are correctly positioned but twisted
   for(int i=0;i<4;i++){
       
       if(rubics_cube[1][9]==rubics_cube[1][5] && rubics_cube[5][7]==rubics_cube[5][5] && rubics_cube[3][3]==rubics_cube[3][5]){
           spin_cw(1);
           continue;
       }
       
       int x,y;
       
       if(rubics_cube[1][9]==rubics_cube[3][5]){
           x=rubics_cube[5][7];
           y=rubics_cube[3][3];
       }
       
       if(rubics_cube[5][7]==rubics_cube[3][5]){
           x=rubics_cube[1][9];
           y=rubics_cube[3][3];
       }
       
       if(rubics_cube[3][3]==rubics_cube[3][5]){
           x=rubics_cube[5][7];
           y=rubics_cube[1][9];
       }
       
      if((x==rubics_cube[1][5] && y==rubics_cube[5][5]) || (x==rubics_cube[5][5] && y==rubics_cube[1][5])){
         to_fix_with_righty_alg();
      }else{
          righty_alg(1);
          bottom_layer_corners();
      }

      spin_cw(1);
   }
   

}

void cube::to_move_edge_right(){
   top_face_cw(1);
   righty_alg(1);
   spin_cw(1);
   lefty_alg(1);
}

void cube::to_move_edge_left(){
   top_face_acw(1);
   lefty_alg(1);
   spin_acw(1);
   righty_alg(1);
}

void cube::second_layer_edges(){//To solve 2nd layer edges
int x,y,t=8;
  while(t--){

   if(rubics_cube[1][2]!=rubics_cube[0][5] && rubics_cube[0][8]!=rubics_cube[0][5]){
     x=rubics_cube[1][2];
     y=rubics_cube[0][8];

     while(x!=rubics_cube[1][5]){
        bottom_2layers_acw(1);
     }

     if(x==rubics_cube[1][5]){
        if(y==rubics_cube[2][5]){
           to_move_edge_left();
        }
        if(y==rubics_cube[5][5]){
           to_move_edge_right();
        }
     }else{
        bottom_2layers_acw(1);
     }
   }else{
     top_face_acw(1);
   }

  }
  
  //handle edge cases like required edge is in second layer but swaped
  int z=8;
  while(z--){
     if(rubics_cube[1][6]!=rubics_cube[1][5]){
       to_move_edge_right();
       second_layer_edges();
     }else{
        spin_cw(1);
     }
  }
}

int cube::check_form_in_step4(){
  int x=0;
   if((rubics_cube[0][4]==rubics_cube[0][5] && rubics_cube[0][6]==rubics_cube[0][5])||(rubics_cube[0][2]==rubics_cube[0][5] && rubics_cube[0][8]==rubics_cube[0][5])){
      if(rubics_cube[0][2]==rubics_cube[0][5] && rubics_cube[0][8]==rubics_cube[0][5]){
         spin_acw(1);
      }
      x=1; //for a line
      if(rubics_cube[0][2]==rubics_cube[0][5] && rubics_cube[0][8]==rubics_cube[0][5])
      x=2; //already plus
   }else{
      int k=0;
      while(rubics_cube[0][6]!=rubics_cube[0][5] || rubics_cube[0][8]!=rubics_cube[0][5]){
          spin_acw(1);
          k++;
          if(k>4)
          break;
      }

      if(k<=4)
      x=3;
   }

   return x;
}

void cube::top_layer_plus_step4(){
int x=check_form_in_step4();
   if(x==2)
   return;

   if(x==1){
      front_face_cw(1);
      righty_alg(1);
      front_face_acw(1);
   }

   if(x==3){
     face_2layers_cw(1);
     righty_alg(1);
     face_2layers_acw(1);
   }

   if(x==0){
      front_face_cw(1);
      righty_alg(1);
      front_face_acw(1);

      check_form_in_step4();
      face_2layers_cw(1);
      righty_alg(1);
      face_2layers_acw(1);
   }

}

void cube::sqnce_in_step5(){
   righty_alg(3);
   spin_cw(1);
   lefty_alg(3);
}

int cube::check_form_in_step5(){
   //return 1 if properly arranged already, 2 if corners on right face top layer are not proper
   //3 if diagnol elements are not proper

   int count=0,i=0;
   vector<int> v(4);
   vector<vector<pair<int,int>>> positions;
   
   //storing corners of top layer in U shape
   positions.push_back({make_pair(0,1),make_pair(2,1),make_pair(4,3)});
   positions.push_back({make_pair(0,7),make_pair(2,3),make_pair(1,1)});
   positions.push_back({make_pair(0,9),make_pair(5,1),make_pair(1,3)});
   positions.push_back({make_pair(0,3),make_pair(4,1),make_pair(5,3)});

   while(1){
      for(int i=0;i<4;i++)
      v[i]=0;

      count=0;
      for(int i=0;i<4;i++){
         pair<int,int> p1,p2,p3;
         p1=positions[i][0];
         p2=positions[i][1];
         p3=positions[i][2];

         int x,y,z;
         if(rubics_cube[p1.first][p1.second]!=rubics_cube[0][5] && rubics_cube[p2.first][p2.second]!=rubics_cube[0][5]){
           x=rubics_cube[p1.first][p1.second];
           y=rubics_cube[p2.first][p2.second];
         }
         else if(rubics_cube[p2.first][p2.second]!=rubics_cube[0][5] && rubics_cube[p3.first][p3.second]!=rubics_cube[0][5]){
           x=rubics_cube[p2.first][p2.second];
           y=rubics_cube[p3.first][p3.second];
         }else{
         x=rubics_cube[p1.first][p1.second];
         y=rubics_cube[p3.first][p3.second];
         }

         if((x==rubics_cube[p2.first][5] && y==rubics_cube[p3.first][5])||(x==rubics_cube[p3.first][5] && y==rubics_cube[p2.first][5])){
          v[i]=1;
         }else{
           count++;
         }
      }

      if(count>=3){
         top_face_cw(1);
      }else{
          if(count==0){
             return 1;
          }else{
            if((v[0]==0 && v[2]==0)||(v[1]==0 && v[3]==0)){

               return 3;
            }

            if(v[0]==0 && v[3]==0){
               spin_cw(1);
               return 2;
            }

            if(v[1]==0 && v[2]==0){
               spin_acw(1);
               return 2;
            }

            if(v[2]==0 && v[3]==0){
               return 2;
            }
          }
      }
   }
   
}

void cube::position_toplayer_corners(){ 
   int x=check_form_in_step5();
   while(x!=1){
      sqnce_in_step5();
      x=check_form_in_step5();
   }
}

void cube::twisting_top_layer_corners(){//To solve top layer corners
   rotate_upside_down();
  int t=4;
  while(t--){
    while(rubics_cube[3][3]!=rubics_cube[3][5]){
      righty_alg(1);
    }

    bottom_face_cw(1);
  }
  rotate_upside_down();

  while(rubics_cube[1][1]!=rubics_cube[1][5]){
   bottom_2layers_acw(1);
  }
}

void cube::sqnce_for_top_layer_edges(){
   righty_alg(1);
   lefty_alg(1);

   righty_alg(5);
   lefty_alg(5);
}

int cube::check_form_in_lst_step(){
   int x,count=0,j;
   //give 0 for 1 face solved
   //1 for completely solved
   //2 for not solved even 1 face

   for(int i=0;i<4;i++){
      if(rubics_cube[1][2]==rubics_cube[1][5]){
          count++;
          j=i;
      }
      spin_cw(1);
   }
   if(count==0)
   return 2;

   if(count==4)
   return 1;

   if(count==1){
      while(rubics_cube[1][2]!=rubics_cube[1][5])
      spin_cw(1);
      
      return 0;
   }

   return 0;
}

void cube::top_layer_edges(){ //To solve top layer edges
   int x=check_form_in_lst_step();
   if(x==1){
      return;
   }else if(x==0){
      sqnce_for_top_layer_edges();
      
      int x=check_form_in_lst_step();
      if(x==0){
         sqnce_for_top_layer_edges();
      }

      return;
   }else if(x==2){
      sqnce_for_top_layer_edges();

      int x=check_form_in_lst_step();

      while(x!=1){
         sqnce_for_top_layer_edges();
         x=check_form_in_lst_step();
      }
      
   }
}


int main(){
    
  cube c;

  cout << "Give Initial State of Cube:\n";
  c.take_input();
  
  c.bottom_face_plus();

  cout << "\nCube After Solving Bottom Layer Edges:\n";
  c.print_cube();
  cout << "\n";

  c.bottom_layer_corners();

  cout << "Cube After Solving Bottom Layer Corners:\n";
  c.print_cube();
  cout << "\n";
   
  c.second_layer_edges();

  cout << "Cube After Solving Middle Layer Edges:\n";
  c.print_cube();
  cout << "\n";
  
  c.top_layer_plus_step4();

  cout << "Cube After Making PLUS in Top face:\n";
  c.print_cube();
  cout << "\n";

  c.position_toplayer_corners();

  cout << "Cube After Positioning Top Layer Corners:\n";
  c.print_cube();
  cout << "\n";

  c.twisting_top_layer_corners();

  cout << "Cube After Solving Top Layer corners:\n";
  c.print_cube();
  cout << "\n";

  c.top_layer_edges();

  cout << "Cube After Solving Top Layer Edges:\n";
  c.print_cube();
  cout << "\n";

  cout << "Solved Cube:\n";
  c.print_cube();
  cout << "\n";
}

/*
give top face of cube:
r g r w y o g y o
give front face of cube:
y b b w r w b o y
give left face of cube:
y g o g b b w y w
give down face of cube:
r g b o w w g b w
give back face of cube:
g r g y o y b r o
give right face of cube:
y b w r g r r o o
*/

/*
top face
y g b y y w g b o
front face
r r b w r y g o g
left face
o g y y b o w b w
down face
o g r w w o b y w
back face
y r g w o o b b r
right face
y g r r g r w b o

*/
