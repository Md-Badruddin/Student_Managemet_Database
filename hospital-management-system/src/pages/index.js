import React from 'react';
import Link from 'next/link';
import Layout from '../components/Layout';

const Home = () => {
    return (
        <Layout>
            <h1>Welcome to the Hospital Management System</h1>
            <p>Your one-stop solution for managing hospital operations efficiently.</p>
            <h2>Navigation</h2>
            <ul>
                <li>
                    <Link href="/patients">Patients</Link>
                </li>
                <li>
                    <Link href="/appointments">Appointments</Link>
                </li>
                <li>
                    <Link href="/staff">Staff</Link>
                </li>
            </ul>
        </Layout>
    );
};

export default Home;