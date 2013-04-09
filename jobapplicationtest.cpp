#include "savedjobtest.h"

TEST(JobApplication, createJobApplication) {
	JobSeeker* jobSeekerWithResume = createJobSeekerWithResume();
	JobSeeker* jobSeekerWithoutResume = createJobSeekerWithoutResume();
	Job* atsJob = createATSJob();
	Job* JReqJob = createJReqJob();
	JobSeekerSaveJob* jobSeekerSaveJob = new JobSeekerSaveJob();
	SavedJob* savedJob = new SavedJob(atsJob, jobSeekerWithResume);
	Resume* resume = new Resume();
	JobApplication(atsJob, jobSeekerWithResume, resume);
	/*
	Jobs* jobs = jobSeekerSaveJob->getAllJobs(jobSeekerWithResume);
	EXPECT_EQ(jobs->atIndex(0), atsJob);
	EXPECT_EQ(jobs->atIndex(1), JReqJob);
*/
}

