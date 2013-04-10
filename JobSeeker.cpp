#include"JobSeeker.h"

JobSeeker::JobSeeker(Resume* resume) {
	_resume = resume;
}

bool JobSeeker::hasResume() {
	if(_resume != NULL)
		return true;
	if(_resume == NULL)
		return false;
}

Resume* JobSeeker::currentResume() {
	return _resume;
}

JobSeekers::JobSeekers() {
	vector<JobSeeker*> jobSeekers;
	_jobSeekers = jobSeekers;
}

void JobSeekers::addJobSeeker(JobSeeker* jobSeeker) {
	_jobSeekers.push_back(jobSeeker);
}
