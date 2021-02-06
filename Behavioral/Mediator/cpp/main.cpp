#include "person.hpp"
#include "ChatRoom.hpp"

int main(){
    ChatRoom room;
    
    Person john{"John"};
    Person jane{"Jane"};

    room.join(&john);
    room.join(&jane);

    john.say("Hi! everyone.");
    jane.say("Hey, John!");

    Person simon{"Simon"};
    room.join(&simon);
    simon.say("Hi everybody!");

    jane.private_message("simon", "glad you found us!");
    return 0;
}