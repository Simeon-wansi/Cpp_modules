#include <iostream>
#include <vector>


// int main()
// {
//     std::vector<int> numbers;

//     numbers.push_back(10);
//     numbers.push_back(20);
//     numbers.push_back(30);

//     std::cout << "First element: " << numbers[0] << "\n";  // access
//     std::cout << "Size: " << numbers.size() << "\n";

//     for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it){
//         std::cout << *it << " ";
//     }
// }


// #include <iostream>
// #include <map>
// #include <string>



// int main()
// {
//     std::map<std::string, int> scores;

//     scores["Alice"] = 90;
//     scores["Bob"] = 75;

//     //Access 
//     std::cout << scores["Alice"] << std::endl;

//     for (std::map<std::string, int>::iterator it = scores.begin(); it != scores.end(); ++it)
//     {
//         std::cout << it->first << " => " << it->second << std::endl;
//     }

// }

// #include <iostream>
// #include <map>
// #include <string>


// class Channel{
//     public:
//     std::string _name;
//     Channel(std::string n) : _name(n){}
// };

// class Server{
//     std::map<std::string, Channel*> channels;

//     public:
//         void addChannel(const std::string &name)
//         {
//             channels[name] = new Channel(name);
//         }

//         std::map<std::string, Channel*> getChannels(){
//             return channels ;
//         }
// };


// int  main()
// {
//     Server server;
//     server.addChannel("General");
//     server.addChannel("random");

//     std::map<std::string, Channel*> chs = server.getChannels();
//     for (std::map<std::string, Channel*>::iterator it =  chs.begin(); it != chs.end(); ++it)
//     {
//         std::cout<< it->first << "=>" << it->second->_name << std::endl;
//     }

//     for(std::map<std::string, Channel*>::iterator it =  chs.begin() ; it != chs.end(); ++it)
//     {
//         delete it->second;
//     }
// }