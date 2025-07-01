#include <LedMatrixDrawer.h>
#include <LedMatrixDrawerConfig.h>

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

LedMatrixDrawer drawer;

const bool* const animation[] = {
  &m_matrix[0][0],
  &i_matrix[0][0],
  &a_matrix[0][0],
  &u_matrix[0][0],
  &m_matrix[0][0],
  &o_matrix[0][0],
  &r_matrix[0][0]
};


int numBitmaps;
void setup() {
  numBitmaps = sizeof(animation) / sizeof(animation[0]);
}

void loop() {
  drawer.sweepArray(animation,numBitmaps,1500,250);
  delay(1000);
}

