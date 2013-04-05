#include"Job.h"

JobCollection::JobCollection() {
	vector<Job*> jobs;
	_jobs = jobs;
}

void JobCollection::addJobToCollection(Job * job)
{
	_jobs.push_back(job);
}

Job* JobCollection::atIndex(int index)
{
	return _jobs[index];
}
