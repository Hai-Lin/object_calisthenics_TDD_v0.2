#include"testhelper.h"

Job* createATSJob() {
	Recruiter* recruiter = new Recruiter();
	ATSJob* job = new ATSJob(recruiter);
	return job;
}

Job* createJReqJob() {
	JobType type = JReq;
	Recruiter* recruiter = new Recruiter();
	Job* job = new Job(recruiter,type);
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
