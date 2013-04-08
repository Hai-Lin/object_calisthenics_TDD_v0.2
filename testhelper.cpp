#include"testhelper.h"

Job* createATSJob() {
	JobType type = ATS;
	Job* job = new Job(type);
	return job;
}

Job* createJReqJob() {
	JobType type = JReq;
	Job* job = new Job(type);
	return job;
}

JobSeeker* createJobSeekerWithResume() {
	Resume* resume = new Resume();
	JobSeeker* jobSeeker = new JobSeeker(resume);
	return jobSeeker;
}

JobSeeker* createJobSeekerWithoutResume() {
	JobSeeker* jobSeeker = new JobSeeker();
	return jobSeeker;
}
