import { useEffect, useState } from 'react';
import { useRouter } from 'next/router';
import Layout from '../../components/Layout';

const AppointmentDetail = () => {
    const router = useRouter();
    const { id } = router.query;
    const [appointment, setAppointment] = useState(null);
    const [loading, setLoading] = useState(true);

    useEffect(() => {
        if (id) {
            const fetchAppointment = async () => {
                const response = await fetch(`/api/appointments/${id}`);
                const data = await response.json();
                setAppointment(data);
                setLoading(false);
            };
            fetchAppointment();
        }
    }, [id]);

    if (loading) {
        return <div>Loading...</div>;
    }

    if (!appointment) {
        return <div>No appointment found.</div>;
    }

    return (
        <Layout>
            <h1>Appointment Details</h1>
            <p><strong>ID:</strong> {appointment.id}</p>
            <p><strong>Patient:</strong> {appointment.patientName}</p>
            <p><strong>Date:</strong> {appointment.date}</p>
            <p><strong>Time:</strong> {appointment.time}</p>
            <p><strong>Doctor:</strong> {appointment.doctorName}</p>
            <p><strong>Notes:</strong> {appointment.notes}</p>
        </Layout>
    );
};

export default AppointmentDetail;