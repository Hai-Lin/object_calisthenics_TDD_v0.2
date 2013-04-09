#include <gtest/gtest.h>
#include "testhelper.h"

TEST(EmptyTest, emptytest) {
}

TEST(JobSeekersCanSaveJob, saveOneJob) {
	JobSeeker* jobSeeker = new JobSeeker();	
	Job* job = createATSJob();
	JobSeekerSaveJob* jobSeekerSaveJob = new JobSeekerSaveJob();
	jobSeekerSaveJob->saveJob(jobSeeker, job);
}

TEST(JobSeekerHaveResume, haveResumeTest) {
	JobSeeker* jobSeekerWithResume = createJobSeekerWithResume();
	JobSeeker* jobSeekerWithoutResume = createJobSeekerWithoutResume();
	EXPECT_TRUE(jobSeekerWithResume->hasResume());
	EXPECT_FALSE(jobSeekerWithoutResume->hasResume());
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest( &argc, argv );
	return RUN_ALL_TESTS();
}
