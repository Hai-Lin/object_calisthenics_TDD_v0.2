#include "savedjobtest.h"

TEST(JobApplication, createJobApplication) {
	Date* date;
	JobSeeker* jobSeekerWithResume = createJobSeekerWithResume();
	JobSeeker* jobSeekerWithoutResume = createJobSeekerWithoutResume();
	Job* atsJob = createATSJob();
	Job* JReqJob = createJReqJob();
	Resume* resume = new Resume();
	JobApplication(jobSeekerWithResume, atsJob, date);
}

