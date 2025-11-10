import { useEffect, useState } from 'react';
import { useRouter } from 'next/router';
import Layout from '../../components/Layout';

const PatientDetails = () => {
    const router = useRouter();
    const { id } = router.query;
    const [patient, setPatient] = useState(null);
    const [loading, setLoading] = useState(true);
    const [error, setError] = useState(null);

    useEffect(() => {
        if (id) {
            const fetchPatient = async () => {
                try {
                    const response = await fetch(`/api/patients/${id}`);
                    if (!response.ok) {
                        throw new Error('Failed to fetch patient data');
                    }
                    const data = await response.json();
                    setPatient(data);
                } catch (err) {
                    setError(err.message);
                } finally {
                    setLoading(false);
                }
            };

            fetchPatient();
        }
    }, [id]);

    if (loading) return <div>Loading...</div>;
    if (error) return <div>Error: {error}</div>;

    return (
        <Layout>
            <h1>Patient Details</h1>
            {patient ? (
                <div>
                    <h2>{patient.name}</h2>
                    <p>Age: {patient.age}</p>
                    <p>Gender: {patient.gender}</p>
                    <p>Medical History: {patient.medicalHistory}</p>
                    {/* Add more patient details as needed */}
                </div>
            ) : (
                <p>No patient found.</p>
            )}
        </Layout>
    );
};

export default PatientDetails;