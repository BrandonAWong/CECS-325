#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

class Bucket {
    public:
        Bucket() { }

        void generate(int size, int min, int max) {
            for (std::size_t i {0}; i < size; ++i)
               v.push_back(std::rand() % abs(min) - max - 1 + min);
        }

        void sort() {
            int temp {};
            for (std::size_t i {0}; i < size(); ++i) {
            
                for (std::size_t j {i+1}; j < size(); ++j)
                    if (v[i] > v[j]) {
                        temp = v[i];
                        v[i] = v[j];
                        v[j] = temp;
                    }
            }
        }

        int size() { return v.size(); }

        int atIndex(int i) { return v[i]; }

        void merge(Bucket b) {
            int temp[size()+b.size()];
                std::size_t i {0}, currentIndex1 {0}, currentIndex2 {0};
                while (currentIndex1 < size() && currentIndex2 < b.size())
                {
                    temp[i++] =  (v[currentIndex1] < b.v[currentIndex2]) ? v[currentIndex1++] : b.v[currentIndex2++];
                }
                while (currentIndex1 < size())
                    temp[i++] =  v[currentIndex1++];
                while (currentIndex2 < b.size())
                    temp[i++] =  b.v[currentIndex2++];

                for (std::size_t i {0}; i < size()+b.size(); ++i) {
                    if (i < size())
                       v[i] = temp[i]; 
                    else
                        v.push_back(temp[i]);
                }
        }

    private:
        std::vector<int> v;
};

int globalSwapCount {0};
int main(int argc, char *argv[])
{
    std::srand(std::time(0));
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
    for (int i {0}; i<bucketCount; i++) // creating bucketCount Buckets
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
        std::cout << "yo\n";
        endGame.merge(list[0]); // merge first bucket in list into endGame
        list.erase(list.begin()); // erase the first bucket in the list
    }
    // write all the numbers in endGame bucket to a file
    std::fstream out("bucketList.out", std::ios::out);
    for(int i=0; i<endGame.size(); i++) // Bucket::size()
        out << endGame.atIndex(i) << std::endl; // Bucket::atIndex(int)
    std::cout << "Global Swap Count:"<< globalSwapCount << '\n';
    std::cout << "\nbucketList.out has "<<bucketCount * bucketSize<< " sorted numbers\n";
    return 0;
}

