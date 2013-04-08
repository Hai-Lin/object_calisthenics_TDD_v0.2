#include <gtest/gtest.h>
#include "Recruiter.h"
#include "JobSeeker.h"
#include "Job.h"

TEST(EmptyTest, emptytest) {
}

TEST(JobSeekersCanSaveJob, saveOneJob) {
	JobSeeker* jobSeeker = new JobSeeker();	
	Job * job = new Job();
	jobSeeker->saveJob(job);
}

TEST(JobSeekersCanApplyJob, applyOneJob) {
	JobSeeker* jobSeeker = new JobSeeker();	
	Job * job = new Job();
	jobSeeker->applyJob(job);
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest( &argc, argv );
	return RUN_ALL_TESTS();
}
