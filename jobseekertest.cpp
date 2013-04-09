#include <gtest/gtest.h>
#include "testhelper.h"

TEST(EmptyTest, emptytest) {
}

TEST(JobSeekerHaveResume, haveResumeTest) {
	JobSeeker* jobSeekerWithResume = createJobSeekerWithResume();
	JobSeeker* jobSeekerWithoutResume = createJobSeekerWithoutResume();
	EXPECT_TRUE(jobSeekerWithResume->hasResume());
	EXPECT_FALSE(jobSeekerWithoutResume->hasResume());
}

TEST(JobSeekersCanApplyJob, applyOneJob) {
	JobSeeker* jobSeekerWithResume = createJobSeekerWithResume();
	JobSeeker* jobSeekerWithoutResume = createJobSeekerWithoutResume();
	Job* atsJob = createATSJob();
	Job* JReqJob = createJReqJob();
	JobSeekerApplyJob* jobSeekerApplyJob = new JobSeekerApplyJob();
	EXPECT_TRUE(jobSeekerApplyJob->applyJob(jobSeekerWithResume, atsJob));
	EXPECT_TRUE(jobSeekerApplyJob->applyJob(jobSeekerWithResume, JReqJob));
	EXPECT_TRUE(jobSeekerApplyJob->applyJob(jobSeekerWithoutResume, atsJob));
	EXPECT_FALSE(jobSeekerApplyJob->applyJob(jobSeekerWithoutResume, JReqJob));
	Jobs* jobs = jobSeekerApplyJob->getAllJobs(jobSeekerWithResume);
	EXPECT_EQ(jobs->atIndex(0), atsJob);
	EXPECT_EQ(jobs->atIndex(1), JReqJob);
	JobSeeker* jobSeeker = createJobSeekerWithResume();
	jobs = jobSeekerApplyJob->getAllJobs(jobSeeker);
	EXPECT_EQ(NULL, jobs);
}

TEST(JobSeekersCanSaveJob, savejob) {
	JobSeeker* jobSeekerWithResume = createJobSeekerWithResume();
	JobSeeker* jobSeekerWithoutResume = createJobSeekerWithoutResume();
	Job* atsJob = createATSJob();
	Job* JReqJob = createJReqJob();
	JobSeekerSaveJob* jobSeekerSaveJob = new JobSeekerSaveJob();
	jobSeekerSaveJob->saveJob(jobSeekerWithResume, atsJob);
	jobSeekerSaveJob->saveJob(jobSeekerWithResume, JReqJob);
	jobSeekerSaveJob->saveJob(jobSeekerWithoutResume, JReqJob);
	jobSeekerSaveJob->saveJob(jobSeekerWithoutResume, atsJob);
	Jobs* jobs = jobSeekerSaveJob->getAllJobs(jobSeekerWithResume);
	EXPECT_EQ(jobs->atIndex(0), atsJob);
	EXPECT_EQ(jobs->atIndex(1), JReqJob);
}


int main(int argc, char **argv) {
	::testing::InitGoogleTest( &argc, argv );
	return RUN_ALL_TESTS();
}
