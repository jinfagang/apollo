/**
 * 
 * simple component based on Cyber RT framework
 * */

#include "cyber/cyber.h"
#include "cyber/time/rate.h"
#include "cyber/time/time.h"


#include "./proto/bbox_array.pb.h"


using apollo::cyber::Rate;
using apollo::cyber::Time;
using apollo::cyber_tests::detection::proto::Chatter;

int main(int argc, char *argv[]) {
    apollo::cyber::Init(argv[0]);

    auto publisher_node = apollo::cyber::CreateNode("publisher");
    auto publisher = publisher_node->CreateWriter<Chatter>("channel/chatter");

    Rate rate(1.0);
    while(apollo::cyber::OK()){
        /* code */
        static uint64_t seq=0;
        auto msg = std::make_shared<Chatter>();

        msg->set_timestamp(Time::Now().ToNanosecond());
        msg->set_content("hello! from cyber publisher!.");
        publisher->Write(msg);

        AINFO < "published a message.";
        rate.Sleep();
    }
    return 0;
}