#ifndef io_hpp
#define io_hpp

#include "framework.hpp"

namespace anticheat {
	class io {
	public:
		class irp_io_context {
		public:
			PDEVICE_OBJECT m_device_object = nullptr;
			PIRP m_irp = nullptr;
			PIO_STACK_LOCATION m_isl = nullptr;
			PIO_STATUS_BLOCK m_status_block = nullptr;

			irp_io_context(PDEVICE_OBJECT device_object, PIRP irp, PIO_STACK_LOCATION isl)
				: m_device_object(device_object), m_irp(irp), 
				m_isl(isl), 
				m_status_block(&irp->IoStatus) {}
		};

		using pirp_io_context = irp_io_context*;

		static NTSTATUS irp_handler(PDEVICE_OBJECT device_object, PIRP irp);
	private:
		static NTSTATUS create_handler(pirp_io_context context);
		static NTSTATUS device_control_handler(pirp_io_context context);
	};
}

#endif // !io_hpp