#include "JobApplication.h"

JobApplication::JobApplication(Job* job, JobSeeker* jobSeeker, Resume* resume) {
	_job = job;
	_jobSeeker = jobSeeker;
	_resume = resume;
}
