#include <gtest/gtest.h>
#include "Recruiter.h"
#include "JobSeeker.h"
#include "Job.h"
#include "Resume.h"

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

TEST(EmptyTest, emptytest) {
}

TEST(JobSeekersCanSaveJob, saveOneJob) {
	JobSeeker* jobSeeker = new JobSeeker();	
	Job* job = createATSJob();
	jobSeeker->saveJob(job);
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
