#include "JobApplication.h"

JobApplicatorInfo::JobApplicatorInfo(JobSeeker* jobSeeker) {
	_jobSeeker = jobSeeker;
	_resume = jobSeeker->currentResume();
}

JobApplicatorInfo::JobApplicatorInfo(JobSeeker* jobSeeker, Resume* resume) {
	_jobSeeker = jobSeeker;
	_resume = resume;
}	

bool JobApplicatorInfo::isAppliedBy(JobSeeker* jobSeeker) {
	return _jobSeeker == jobSeeker;
}

void JobApplicatorInfo::addJobSeekerTo(JobSeekers* jobSeekers) {
	jobSeekers->addJobSeeker(_jobSeeker);
}

