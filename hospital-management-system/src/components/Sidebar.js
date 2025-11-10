import React from 'react';
import Link from 'next/link';
import styles from '../styles/components.css';

const Sidebar = () => {
    return (
        <div className={styles.sidebar}>
            <h2>Hospital Management</h2>
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
        </div>
    );
};

export default Sidebar;