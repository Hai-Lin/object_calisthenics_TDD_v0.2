#include "Job.h"
#include "JobSeeker.h"
#include "Resume.h"

class JobApplication {
	private:
		Job* _job;
		JobSeeker* _jobSeeker;
		Resume* _resume;
	public:
		JobApplication(Job* job, JobSeeker* jobSeeker, Resume* resume = NULL);
};
