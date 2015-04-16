#include <vector>
#include <iostream>

namespace aalgo
{

class Job
{
public:
    int start;
    int end;

    Job();
    // Construct a new job where the interval begins at a and ends at b
    Job(int a, int b);

    // Return true if there is overlap in the interval that is self and the interval that is the parameter job.  A shared endpoint is not considered overlap.
    bool Overlap(Job job);

    bool operator==(const Job &job) const;
    friend std::ostream& operator<<(std::ostream &os, Job const &job);
};

// Given a set of intervals that are considered equally paying jobs of varying lengths of time, return the subset that is the optimal selection of jobs (intervals) that.  Provably correct algorithm that's reasonably efficient.
std::vector<aalgo::Job> optimalScheduling(std::vector<aalgo::Job>);

} // namespace aalgo

