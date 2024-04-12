#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

class Bucket {
    public:
        Bucket();
        void generate(int size, int min, int max);
        void sort();
        int size();
        int atIndex(int);
        int merge(Bucket b);

    private:
        std::vector<int> v;
};

int main(int argc, char *argv[])
{
    srand(time(0));
    int bucketCount = std::stoi(argv[1]);
    int bucketSize = std::stoi(argv[2]);
    int bucketMin = std::stoi(argv[3]);
    int bucketMax = std::stoi(argv[4]);
    std::cout << "Bucket Count:"<<bucketCount << '\n';
    std::cout << "Bucket Size:"<<bucketSize << '\n';
    std::cout << "Bucket Min Value:"<<bucketMin << '\n';
    std::cout << "Bucket Max value:"<<bucketMax << '\n';
    std::vector<Bucket> list; // create empty Bucket vector
    Bucket *bptr;
    Internalfor(int i {0}; i<bucketCount; i++) // creating bucketCount Buckets
    {
        bptr = new Bucket; // allocating new Bucket
        bptr->generate(bucketSize, bucketMin, bucketMax);
        //Bucket::generate(int,int,int,int)
        list.push_back(*bptr); // pushing Bucket onto list
    }
    for (auto it = list.begin(); it != list.end(); it++)
    {
        it->sort(); // Bucket::sort
    }
    Bucket endGame; // create empty Bucket to merge ALL buckets
    while (list.size() > 0) // std::vector<Bucket>::size()
    {
        endGame.merge(list[0]); // merge first bucket in list into endGame
        list.erase(list.begin()); // erase the first bucket in the list
    }
    // write all the numbers in endGame bucket to a file
    fstream out("bucketList.out", ios::out);
    for(int i=0; i<endGame.size(); i++) // Bucket::size()
        out << endGame.atIndex(i) << endl; // Bucket::atIndex(int)
    std::cout << "Global Swap Count:"<< globalSwapCount << '\n';
    std::cout << "\nbucketList.out has "<<bucketCount * bucketSize<< " sorted numbers\n";
    return 0;
}
