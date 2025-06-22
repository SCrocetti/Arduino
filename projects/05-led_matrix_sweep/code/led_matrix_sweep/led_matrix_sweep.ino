const bool on = true;
const long delay_time = 500;
const int sweeps=400;
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
void setup() {
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
  bool m_matrix[6][6]={
    {true,false,false,false,false,true},
    {true,true,false,false,true,true},
    {true,false,true,true,false,true},
    {true,false,true,true,false,true},
    {true,false,false,false,false,true},
    {true,false,false,false,false,true}
  };
  sweepMatrix(m_matrix,sweeps);
  
  delay(delay_time);
  bool u_matrix[6][6]={
    {true,false,false,false,false,true},
    {true,false,false,false,false,true},
    {true,false,false,false,false,true},
    {true,false,false,false,false,true},
    {true,false,false,false,false,true},
    {true,true,true,true,true,true}
  };
  sweepMatrix(u_matrix,sweeps);
  delay(delay_time);
  
  bool a_matrix[6][6]={
    {true,true,true,true,true,true},
    {true,false,false,false,false,true},
    {true,false,false,false,false,true},
    {true,true,true,true,true,true},
    {true,false,false,false,false,true},
    {true,false,false,false,false,true}
    
  };
  sweepMatrix(a_matrix,sweeps);
  delay(delay_time);
}

void sweepMatrix(bool matrix[6][6],int sweeps){
  for(int k=0;k<sweeps;k++){
    for(int i=0;i<6;i++){
      digitalWrite(transition_matrix[i][0][0],HIGH);
      for(int j=0;j<6;j++){
        if(matrix[i][j]){
          digitalWrite(transition_matrix[i][j][1],LOW);
        }
      }
      digitalWrite(transition_matrix[i][0][0],LOW);
      for(int j=0;j<6;j++){
        if(matrix[i][j]){
          digitalWrite(transition_matrix[i][j][1],HIGH);
        }
      }
    }
  }
  
}