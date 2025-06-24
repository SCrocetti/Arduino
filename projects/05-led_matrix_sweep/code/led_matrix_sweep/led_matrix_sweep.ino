const long delay_time = 250;
const int duration=1500;
// represents the position of each led catode and anode
// [0][1][0] row 0 column 1 , catode
// [0][1][1] row 0 column 1 , anode
const int transition_matrix[6][6][2]={
  {{2,3},{2,5},{2,7},{2,9},{2,11},{2,13}},
  {{4,3},{4,5},{4,7},{4,9},{4,11},{4,13}},
  {{6,3},{6,5},{6,7},{6,9},{6,11},{6,13}},
  {{8,3},{8,5},{8,7},{8,9},{8,11},{8,13}},
  {{10,3},{10,5},{10,7},{10,9},{10,11},{10,13}},
  {{12,3},{12,5},{12,7},{12,9},{12,11},{12,13}}
};

bool m_matrix[6][6]={
  {true,false,false,false,false,true},
  {true,true,false,false,true,true},
  {true,false,true,true,false,true},
  {true,false,true,true,false,true},
  {true,false,false,false,false,true},
  {true,false,false,false,false,true}
};

bool i_matrix[6][6]={
  {false,true,true,true,true,false},
  {false,false,true,true,false,false},
  {false,false,true,true,false,false},
  {false,false,true,true,false,false},
  {false,false,true,true,false,false},
  {false,true,true,true,true,false}
};

bool a_matrix[6][6]={
  {true,true,true,true,true,true},
  {true,true,false,false,true,true},
  {true,true,false,false,true,true},
  {true,true,true,true,true,true},
  {true,true,false,false,true,true},
  {true,true,false,false,true,true}
  
};

bool u_matrix[6][6]={
  {true,true,false,false,true,true},
  {true,true,false,false,true,true},
  {true,true,false,false,true,true},
  {true,true,false,false,true,true},
  {true,true,true,true,true,true},
  {true,true,true,true,true,true}
};

bool o_matrix[6][6]={
  {false,true,true,true,true,false},
  {true,true,true,true,true,true},
  {true,true,false,false,true,true},
  {true,true,false,false,true,true},
  {true,true,true,true,true,true},
  {false,true,true,true,true,false}
};

bool r_matrix[6][6]={
  {true,true,true,true,true,true},
  {true,true,false,false,true,true},
  {true,true,false,false,true,true},
  {true,true,true,true,true,true},
  {true,true,false,true,true,false},
  {true,true,false,false,true,true}
};

bool miaumor_array[7][6][6];

void setup() {
  memcpy(miau_array[0], m_matrix, sizeof(m_matrix));
  memcpy(miau_array[1], i_matrix, sizeof(i_matrix));
  memcpy(miau_array[2], a_matrix, sizeof(a_matrix));
  memcpy(miau_array[3], u_matrix, sizeof(u_matrix));

  memcpy(miaumor_array[0], m_matrix, sizeof(m_matrix));
  memcpy(miaumor_array[1], i_matrix, sizeof(i_matrix));
  memcpy(miaumor_array[2], a_matrix, sizeof(a_matrix));
  memcpy(miaumor_array[3], u_matrix, sizeof(u_matrix));
  memcpy(miaumor_array[4], m_matrix, sizeof(m_matrix));
  memcpy(miaumor_array[5], o_matrix, sizeof(o_matrix));
  memcpy(miaumor_array[6], r_matrix, sizeof(r_matrix));

  // Set all pins conected to the led matrix to output
  // we only controll rows 2 to 7 and columns 2 to 7
  for(int i=2;i<14;i++){
    pinMode(i, OUTPUT);
  }
  // Set all catode (odd) pines to high so those leds wont fire whe their row is on high
  for(int i=3;i<14;i+=2){
    digitalWrite(i,HIGH);
  }
}

void loop() {
  //weepArrayOfMatrixes(miau_array, 4, 1500);
  sweepArrayOfMatrixes(miaumor_array, 7, 1500);
}

void sweepMatrix(bool matrix[6][6],int duration_milis){
  // 1000(milliseg)/(execution time of this function) witch is aprox 290 micros
  float frecuencia=3.5;
  float sweeps=frecuencia*(float)duration_milis;
  for(int k=0;k<(int)sweeps;k++){
    for(int i=0;i<6;i++){
      digitalWrite(transition_matrix[i][0][0],HIGH);
      for(int j=0;j<6;j++){
        if(matrix[i][j]){
          digitalWrite(transition_matrix[i][j][1],LOW);
        }
      }
      for(int j=0;j<6;j++){
        if(matrix[i][j]){
          digitalWrite(transition_matrix[i][j][1],HIGH);
        }
      }
      digitalWrite(transition_matrix[i][0][0],LOW);
    } 
  }
}

void sweepArrayOfMatrixes(bool array[][6][6],int amount_element, int duration_ms ){
  for(int i=0;i<amount_element;i++){
    sweepMatrix(array[i], duration_ms);
    delay(delay_time);
  }
}
