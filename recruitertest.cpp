#include "recruitertest.h"


TEST(RecruiterCanSeeAListOfJobTheyPost, postMutipleJob) {
	Recruiter* recruiter = new Recruiter();
	JobsManager* jobsManager = new JobsManager();
	jobsManager->postJob(recruiter,ATS);
	jobsManager->postJob(recruiter,JReq);
	Job* job3 = new Job(recruiter, JReq);
	jobsManager->postJob(job3);
	Jobs* jobs = jobsManager->seeJobsPostBy(recruiter);
	EXPECT_EQ(jobs->atIndex(2), job3);
}

TEST(RecruiterCanSeeJobSeekersByJob, seeJobseekerByJob) {
	Recruiter* recruiter = new Recruiter();
	JobsManager* jobsManager = new JobsManager();
	JobApplicationsManager* jobApplicationsManager = new JobApplicationsManager();
	Job* atsJob = new Job(recruiter, ATS);
	Job* JReqJob = new Job(recruiter, JReq);
	jobsManager->postJob(atsJob);
	jobsManager->postJob(JReqJob);
	JobSeeker* jobSeekerWithResume = createJobSeekerWithResume();
	JobSeeker* jobSeekerWithoutResume = createJobSeekerWithoutResume();
	EXPECT_TRUE(jobApplicationsManager->applyJob(jobSeekerWithResume, atsJob));
	EXPECT_TRUE(jobApplicationsManager->applyJob(jobSeekerWithResume, JReqJob));
	EXPECT_TRUE(jobApplicationsManager->applyJob(jobSeekerWithoutResume, atsJob));
	EXPECT_FALSE(jobApplicationsManager->applyJob(jobSeekerWithoutResume, JReqJob));
	JobSeekers* jobSeekers = jobApplicationsManager->jobSeekersWhoApplied(atsJob);
}
