#include <gtest/gtest.h>
#include "testhelper.h"

TEST(EmptyTest, emptytest) {

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
}


int main(int argc, char **argv) {
	::testing::InitGoogleTest( &argc, argv );
	return RUN_ALL_TESTS();
}