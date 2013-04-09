#include "savedjobtest.h"

TEST(JobApplication, createJobApplication) {
	JobSeeker* jobSeekerWithResume = createJobSeekerWithResume();
	JobSeeker* jobSeekerWithoutResume = createJobSeekerWithoutResume();
	Job* atsJob = createATSJob();
	Job* JReqJob = createJReqJob();
	Resume* resume = new Resume();
	JobApplication(atsJob, jobSeekerWithResume, resume);
}

