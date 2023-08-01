#include "snake.h"

int x,y;
//snake-dynimic_array of coordinate
//will array fine  here
std::vector<std::pair<int, int>> body;
/*
{10,10}->body[0]
{10,11}->body[1]
......and so on
*/
void init_snake(){
    body.clear();
    body.push_back({10,10});
    body.push_back({10,11});
    body.push_back({10,12});
}
void paint_snake(){
    for (int i = 0; i < body.size(); i++)
    { std::pair<int,int>location=body[i];
       move(location.first,location.second);
    //    move(body[i].first,body[i].second)
       addch('#');

    }
    
    // move(x,y);
    addch('#');

}
void move_snake(int direction){
        if(direction==UP){
            x--;
        } 
        else if(direction==DOWN ){
            x++;
        }if(direction==LEFT){
            y--;
        }else if(direction==RIGHT){
            y++;
        }
}