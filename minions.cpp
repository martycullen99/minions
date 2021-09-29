#include <iostream>
#include <thread>
#include <vector>

void namePrint(int k){
  std::cout<<"Hello I am minion number: " << std::to_string(k) << "\n";
}

void overlordThread()
{
  std::cout << "Hello Minions! I am the Overlord!\n";
}

int main (int argc, char** argv) {
  if (argc < 2) {
    std::cerr<<"usage: "<<argv[0]<<" <nbminions>\n";
    return -1;
  }
  //Your code goes here
  std::vector<std::thread> mythreads;
  int numMinions = std::stoi(argv[1]);

  for (int i = 0; i < numMinions; i++){
    std::thread mythread(namePrint, i);
    mythreads.push_back(std::move(mythread)); //pushes thread into mythreads array
  }

  for (auto & t : mythreads)
    {
      if (t.joinable())
	t.join();
      else
	std::cout<<"t is not joinable\n";
    }

  std::thread overlord(overlordThread);
  if(overlord.joinable())
    {
      overlord.join();
    }
  else
    {
      std::cout << "overlord is not joinable\n";
    }
  
  return 0;
}

