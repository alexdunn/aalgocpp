#include <vector>
#include <iostream>
#include "scheduling.hpp"

namespace aalgo
{

// In a realistic example the start and end might be Date objects
Job::Job(int a, int b)
{
    start = a;
    end = b;
}

bool Job::Job::operator==(const Job::Job &job) const
{
    if (start == job.start && end == job.end)
    {
        return true;
    }
    return false;
};

std::ostream& operator<<(std::ostream &os, Job const &job)
{
    return os << "Job(" << job.start << ", " << job.end << ")";
}

bool Job::Overlap(Job job)
{
    // If job1 starts before job2 ends and job2 starts before job1 ends, then there is overlap
    if (job.start < end && start < job.end)
    {
        return true;
    }
    return false;
}


std::vector<aalgo::Job> optimalScheduling(std::vector<aalgo::Job> jobs)
{
    std::cout << "\n\n starting" << std::endl;
    std::vector<aalgo::Job> result;

    while (jobs.size() > 0)
    {
        aalgo::Job earliestEndingJob = jobs[0];
        std::cout << "Setting " << earliestEndingJob << " as earliestEndingJob" << std::endl;
        int earliestEndingJobPosition = 0;
        int j = 0;
        for (auto job : jobs)
        {
            if (job.end < earliestEndingJob.end)
            {
                earliestEndingJob = job;
                earliestEndingJobPosition = j;
            }
            ++j;
        }
        std::cout << "Adding " << earliestEndingJob << " to the result" << std::endl;
        result.push_back(earliestEndingJob);
        std::cout << "About to remove " << jobs[earliestEndingJobPosition] << std::endl;
        jobs.erase(jobs.begin() + earliestEndingJobPosition);
        j = 0;
        for (auto job : jobs)
        {
            if (job.Overlap(earliestEndingJob))
            {
                jobs.erase(jobs.begin() + j);
            }
            ++j;
        }
    }

    return result;
}

} // namespace aalgo