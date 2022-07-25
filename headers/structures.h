#ifndef STRUCTURES_H
#define STRUCTURES_H

// motoshow.db
typedef struct {
     int id;
     char engine[20];
     char frame[20];
     int mark;
     int type;
     int engine_volume;
     int power;
     float price;
} main_struct;

// mark.db
typedef struct {
     int id;
     char mark[50];
} mark_struct;

// type.db
typedef struct {
     int id;
     char type[50];
} type_struct;

#endif