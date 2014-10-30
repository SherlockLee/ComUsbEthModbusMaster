#ifndef __VCRITICALSECTION_HPP
#define __VCRITICALSECTION_HPP

// <VDOC<CLASS=VCriticalSection><DESC=Thread synchronization><FAMILY=Multithreading><AUTHOR=Todd Osborne (todd.osborne@poboxes.com)>VDOC>
class VCriticalSection
{
public:
	VCriticalSection()
		{ InitializeCriticalSection(&m_CriticalSection); }

	virtual ~VCriticalSection()
		{ DeleteCriticalSection(&m_CriticalSection); }

	operator			LPCRITICAL_SECTION()
		{ return &m_CriticalSection; }

	// Enter the critical section
	void				Enter()
		{ EnterCriticalSection(&m_CriticalSection); }

	// Try to enter the critical section, returning immediately if not possible
	BOOL				TryEnter()
		{ 
			return FALSE; //NT4.0 Only TryEnterCriticalSection(&m_CriticalSection); 
		}

	// Leave the critical section
	void				Leave()
		{ LeaveCriticalSection(&m_CriticalSection); }

private:
	// Embedded Member(s)
	CRITICAL_SECTION	m_CriticalSection;
};

#endif	// __VCRITICALSECTION_HPP
