#ifndef TESTHELPER
#define TESTHELPER

#include "utility.h"
#include "Resume.h"
#include "SavedJob.h"
#include "jobapplication.h"
#include "SavedJobsManager.h"
#include "JobApplicationsManager.h"
#include "JobsManager.h"
#include "Job.h"

Job* createATSJob();
Job* createJReqJob();
Job* createJReqJob(Recruiter*);
JobSeeker* createJobSeekerWithResume();
JobSeeker* createJobSeekerWithoutResume();
#endif
