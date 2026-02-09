// Queue.h: This file contains the queue definitions.

EXTERN_C_START

#define AMTPTP_IOCTL_INDEX_HAPTIC_PULSE 0x801
#define IOCTL_AMTPTP_HAPTIC_PULSE CTL_CODE(FILE_DEVICE_UNKNOWN, AMTPTP_IOCTL_INDEX_HAPTIC_PULSE, METHOD_BUFFERED, FILE_ANY_ACCESS)

typedef struct _AMTPTP_HAPTIC_PULSE_REQUEST
{
	ULONG FeedbackClick;
	ULONG FeedbackRelease;
} AMTPTP_HAPTIC_PULSE_REQUEST, *PAMTPTP_HAPTIC_PULSE_REQUEST;

//
// This is the context that can be placed per queue
// and would contain per queue information.
//
typedef struct _QUEUE_CONTEXT {

	ULONG placeholder;

} QUEUE_CONTEXT, *PQUEUE_CONTEXT;

WDF_DECLARE_CONTEXT_TYPE_WITH_NAME(QUEUE_CONTEXT, QueueGetContext)

_IRQL_requires_(PASSIVE_LEVEL)
PCHAR
DbgIoControlGetString(
	_In_ ULONG IoControlCode
);

NTSTATUS
AmtPtpDeviceQueueInitialize(
	_In_ WDFDEVICE Device
);

NTSTATUS
AmtPtpDispatchReadReportRequests(
	_In_ WDFDEVICE Device,
	_In_ WDFREQUEST Request,
	_Out_ BOOLEAN *Pending
);

//
// Events from the IoQueue object
//
EVT_WDF_IO_QUEUE_IO_DEVICE_CONTROL AmtPtpDeviceEvtIoDeviceControl;
EVT_WDF_IO_QUEUE_IO_STOP AmtPtpDeviceEvtIoStop;

EXTERN_C_END
