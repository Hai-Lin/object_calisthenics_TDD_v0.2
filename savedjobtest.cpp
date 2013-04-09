#include "savedjobtest.h"

TEST(JobSeekersCanSaveJob, createSavedJob) {
	JobSeeker* jobSeekerWithResume = createJobSeekerWithResume();
	JobSeeker* jobSeekerWithoutResume = createJobSeekerWithoutResume();
	Job* atsJob = createATSJob();
	Job* JReqJob = createJReqJob();
	JobSeekerSaveJob* jobSeekerSaveJob = new JobSeekerSaveJob();
	SavedJob* savedJob = new SavedJob(atsJob, jobSeekerWithResume);
	/*
	Jobs* jobs = jobSeekerSaveJob->getAllJobs(jobSeekerWithResume);
	EXPECT_EQ(jobs->atIndex(0), atsJob);
	EXPECT_EQ(jobs->atIndex(1), JReqJob);
*/
}

